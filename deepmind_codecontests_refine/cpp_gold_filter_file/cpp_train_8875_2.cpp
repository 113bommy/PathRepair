#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;
const int M = 3e4 + 10;
const int N_AC = 2e6 + 10;
int a[N], p[N];
struct ACAM {
  int scnt;
  int nxt[N_AC][10], fail[N_AC];
  long long cnt[N_AC];
  int root;
  void init() {
    memset(nxt, 0, sizeof(nxt));
    memset(cnt, 0, sizeof(cnt));
    memset(fail, 0, sizeof(fail));
    root = 0;
    scnt = 0;
  }
  int Newnode() {
    int pos = ++scnt;
    fail[pos] = 0;
    memset(nxt[pos], 0, sizeof(nxt[pos]));
    return pos;
  }
  void insert(int len) {
    int tmp = root;
    for (int i = 1; i < len; i++) {
      int id = a[i];
      if (!nxt[tmp][id]) nxt[tmp][id] = Newnode();
      tmp = nxt[tmp][id];
    }
    cnt[tmp] = 1;
  }
  void build() {
    queue<int> q;
    for (int i = 0; i < 10; i++) {
      int tmp = nxt[root][i];
      if (tmp) {
        q.push(tmp);
        fail[tmp] = root;
      }
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      cnt[x] |= cnt[fail[x]];
      for (int i = 0; i < 10; i++) {
        int tmp = nxt[x][i];
        if (tmp) {
          q.push(tmp);
          fail[tmp] = nxt[fail[x]][i];
        } else {
          nxt[x][i] = nxt[fail[x]][i];
        }
      }
    }
  }
} t;
int x;
void dfs(int len, int sum) {
  if (sum > x) return;
  if (sum == x) {
    for (int i = 1; i < len; i++) p[i] = p[i - 1] + a[i];
    bool flag = 0;
    for (int i = 1; i < len; i++) {
      for (int j = i; j < len; j++) {
        int tmp = p[j] - p[i - 1];
        if (tmp != x && x % tmp == 0) {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) {
      t.insert(len);
    }
    return;
  }
  for (int i = 1; i <= 9; i++) {
    a[len] = i;
    dfs(len + 1, sum + i);
  }
}
char s[M];
int dp[N][M];
int main() {
  scanf("%s", s + 1);
  cin >> x;
  dfs(1, 0);
  t.build();
  int n = strlen(s + 1);
  memset(dp, 127, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= 9; k++) {
      if (s[i] == '0' + k) {
        for (int j = 0; j <= t.scnt; j++) {
          if (t.cnt[j] != 1) {
            if (t.cnt[t.nxt[j][k]] != 1) {
              dp[i][t.nxt[j][k]] = min(dp[i][t.nxt[j][k]], dp[i - 1][j]);
            }
          }
        }
      }
      for (int j = 0; j <= t.scnt; j++) {
        if (t.cnt[j] != 1) {
          dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        }
      }
    }
  }
  int ans = 1e9;
  for (int j = 0; j <= t.scnt; j++) {
    if (t.cnt[j] != 1) {
      ans = min(ans, dp[n][j]);
    }
  }
  cout << ans << endl;
}
