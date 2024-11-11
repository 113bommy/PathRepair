#include <bits/stdc++.h>
using namespace std;
const int N = 40 + 10;
const int mod = 1e9 + 7;
const int N_AC = 2e3;
long long dp[N][N][N];
struct ACAM {
  int scnt;
  int nxt[N_AC][2], fail[N_AC];
  int root;
  int Newnode() {
    int pos = ++scnt;
    fail[pos] = 0;
    memset(nxt[pos], 0, sizeof(nxt[pos]));
    return pos;
  }
  void insert(char *t) {
    int len = strlen(t);
    int tmp = root;
    for (int i = 0; i < len; i++) {
      int id = t[i] - '0';
      if (!nxt[tmp][id]) nxt[tmp][id] = Newnode();
      tmp = nxt[tmp][id];
    }
  }
  void build() {
    queue<int> q;
    for (int i = 0; i < 2; i++) {
      int tmp = nxt[root][i];
      if (tmp) {
        q.push(tmp);
        fail[tmp] = root;
      }
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i = 0; i < 2; i++) {
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
  int solve(int n) {
    long long ans = 1ll << n;
    for (int i = 0; i < scnt; i++) {
      memset(dp, 0, sizeof(dp));
      dp[0][0][i] = 1;
      for (int j = 0; j < n; j++)
        for (int x = 0; x < scnt; x++)
          for (int y = 0; y < scnt; y++)
            for (int k = 0; k < 2; k++) {
              int a = nxt[x][k], b = nxt[y][k];
              if (a == scnt || b == scnt) continue;
              dp[j + 1][a][b] += dp[j][x][y];
            }
      for (int j = 0; j < scnt; j++) ans -= dp[n][i][j];
    }
    return ans;
  }
} t;
char s[N];
int main() {
  int n;
  cin >> n;
  scanf("%s", s);
  t.insert(s);
  t.build();
  cout << t.solve(n) << endl;
}
