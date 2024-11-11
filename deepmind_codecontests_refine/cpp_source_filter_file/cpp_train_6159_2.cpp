#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int maxn = 1e3 + 9;
const double pi = acos(-1.0);
const int inf = 1e9;
const long long mod = 100003;
char s[59], t[59], op[maxn];
int f1[59], f2[59];
int dp[maxn][59][59];
void sol(char p[], int f[]) {
  int m = strlen(p);
  f[0] = 0, f[1] = 0;
  for (int i = 1; i < m; ++i) {
    int j = f[i];
    while (j && p[i] != p[j]) j = f[j];
    f[i + 1] = p[i] == p[j] ? j + 1 : 0;
  }
}
pair<int, int> hj(char jk, int j, int k) {
  int p1 = j, p2 = k;
  while (p1 && jk != s[p1]) p1 = f1[p1];
  if (jk == s[p1]) ++p1;
  while (p2 && jk != t[p2]) p2 = f2[p2];
  if (jk == t[p2]) ++p2;
  return make_pair(p1, p2);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> op >> s >> t;
  sol(s, f1);
  sol(t, f2);
  int a = strlen(s), b = strlen(t);
  int n = strlen(op);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j <= a; ++j) {
      for (int k = 0; k <= b; ++k) {
        if (op[i] != '*') {
          pair<int, int> tmp = hj(op[i], j, k);
          int jk = 0;
          if (tmp.first == a) ++jk;
          if (tmp.second == b) --jk;
          dp[i][j][k] = jk + dp[i + 1][tmp.first][tmp.second];
        } else {
          int ans = 0;
          for (int io = 0; io < 26; ++io) {
            pair<int, int> tmp = hj('a' + io, j, k);
            int jk = 0;
            if (tmp.first == a) ++jk;
            if (tmp.second == b) --jk;
            ans = max(ans, jk + dp[i + 1][tmp.first][tmp.second]);
          }
          dp[i][j][k] = ans;
        }
      }
    }
  }
  cout << dp[0][0][0];
  return 0;
}
