#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
const int MAX_N = 105;
const int SON_N = 26;
const int CLD_NUM = SON_N;
char strA[MAXN], strB[MAXN];
char virus[MAXN];
int pre[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
char str[MAXN];
class ACAutomaton {
 public:
  int n, root;
  int id['Z' + 1];
  int fail[MAX_N];
  bool mark[MAX_N];
  int trie[MAX_N][SON_N];
  void init() {
    for (int i = 0; i < SON_N; i++) id[i + 'A'] = i;
  }
  void reset() {
    root = 0;
    memset(trie[root], -1, sizeof(trie[root]));
    mark[root] = false;
    n = 1;
  }
  void insert(char word[]) {
    int p = 0, u = root;
    while (word[p] != '\0') {
      int tid = id[word[p]];
      if (trie[u][tid] == -1) {
        memset(trie[n], -1, sizeof(trie[n]));
        mark[n] = false;
        trie[u][tid] = n++;
      }
      u = trie[u][tid];
      p++;
    }
    mark[u] = true;
  }
  void construct() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < SON_N; i++) {
      if (trie[root][i] != -1) {
        fail[trie[root][i]] = root;
        q.push(trie[root][i]);
      } else
        trie[root][i] = 0;
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (mark[fail[u]]) mark[u] = true;
      for (int i = 0; i < SON_N; i++) {
        int &v = trie[u][i];
        if (v != -1) {
          q.push(v);
          fail[v] = trie[fail[u]][i];
        } else
          v = trie[fail[u]][i];
      }
    }
  }
  void work() {
    memset(pre, -1, sizeof(pre));
    memset(dp, -INF, sizeof(dp));
    int len1 = strlen(strA);
    int len2 = strlen(strB);
    int len = strlen(virus);
    for (int i = 0; i <= len1; i++) dp[i][0][0] = 0;
    for (int i = 0; i <= len2; i++) dp[0][i][0] = 0;
    int offset = len1 + len2 + len;
    for (int i = 1; i <= len1; i++)
      for (int j = 1; j <= len2; j++)
        for (int k = 0; k < n; k++) {
          if (dp[i - 1][j][k] > dp[i][j][k]) {
            dp[i][j][k] = dp[i - 1][j][k];
            pre[i][j][k] = -2;
          }
          if (dp[i][j - 1][k] > dp[i][j][k]) {
            dp[i][j][k] = dp[i][j - 1][k];
            pre[i][j][k] = -3;
          }
          if (strA[i - 1] == strB[j - 1]) {
            int son = strA[i - 1] - 'A';
            int nxt = trie[k][son];
            if (mark[nxt]) continue;
            if (dp[i - 1][j - 1][k] + 1 > dp[i][j][nxt]) {
              pre[i][j][nxt] = k;
              dp[i][j][nxt] = dp[i - 1][j - 1][k] + 1;
            }
          }
        }
    int ans = dp[len1][len2][0], id = 0;
    for (int i = 1; i < n; i++) {
      if (dp[len1][len2][i] > ans) {
        ans = dp[len1][len2][i];
        id = i;
      }
    }
    if (ans == 0) {
      printf("0\n");
      return;
    }
    int x = len1, y = len1, k = id;
    int p = 0;
    while (pre[x][y][k] != -1) {
      if (pre[x][y][k] >= 0) {
        str[p++] = strA[x - 1];
        k = pre[x][y][k];
        x--;
        y--;
      } else if (pre[x][y][k] == -2) {
        x--;
      } else if (pre[x][y][k] == -3) {
        y--;
      }
    }
    for (int i = p - 1; i >= 0; i--) putchar(str[i]);
    printf("\n");
  }
} AC;
int main() {
  while (scanf(" %s", strA) != EOF) {
    scanf(" %s %s", strB, virus);
    AC.init();
    AC.reset();
    AC.insert(virus);
    AC.construct();
    AC.work();
  }
  return 0;
}
