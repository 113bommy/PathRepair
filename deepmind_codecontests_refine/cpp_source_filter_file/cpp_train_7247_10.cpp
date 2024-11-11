#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const long long mod = 1000000009;
int n, m;
int sz = 1, root = 1;
int dat[101][5];
int fail[101];
int a[11];
int en[101], maxx[101];
int dp[1001][101][11];
int ID(char xx) {
  if (xx == 'A') {
    return 0;
  }
  if (xx == 'T') {
    return 1;
  }
  if (xx == 'C') {
    return 2;
  }
  return 3;
}
struct AC_machine {
  void add(string s) {
    int l = s.size();
    int p = root;
    for (int i = 0; i < l; i++) {
      a[i] = ID(s[i]);
      if (!dat[p][a[i]]) {
        dat[p][a[i]] = ++sz;
      }
      p = dat[p][a[i]];
    }
    en[p] = l;
  }
  void build() {
    queue<int> q;
    q.push(root);
    fail[root] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int i = 1; i <= 4; i++) {
        if (dat[x][i]) {
          int p = fail[x];
          while (!dat[p][i] and p) {
            p = fail[p];
          }
          if (!p) {
            p = 1;
          } else {
            p = dat[p][i];
          }
          fail[dat[x][i]] = p;
          q.push(dat[x][i]);
          maxx[dat[x][i]] = max(en[dat[x][i]], maxx[fail[dat[x][i]]]);
        }
      }
    }
    for (int i = 1; i <= sz; i++) {
      for (int j = 1; j <= 4; j++) {
        if (!dat[i][j]) {
          int p = fail[i];
          while (p and !dat[p][j]) {
            p = fail[p];
          }
          if (!p) {
            p = 1;
          } else {
            p = dat[p][j];
          }
          dat[i][j] = p;
        }
      }
    }
  }
} AC;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    AC.add(s);
  }
  AC.build();
  dp[0][1][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= sz; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 4; l++) {
          if (dat[j][l]) {
            if (k + 1 <= maxx[dat[j][l]]) {
              dp[i + 1][dat[j][l]][0] += dp[i][j][k];
              dp[i + 1][dat[j][l]][0] %= mod;
            } else {
              dp[i + 1][dat[j][l]][k + 1] += dp[i][j][k];
              dp[i + 1][dat[j][l]][k + 1] %= mod;
            }
          }
        }
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= sz; i++) {
    res += dp[n][i][0] % mod;
    res %= mod;
  }
  cout << res << endl;
  return 0;
}
