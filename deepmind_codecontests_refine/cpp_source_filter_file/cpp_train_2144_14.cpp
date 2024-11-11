#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1000000007;
const double pi = acos(-1.0);
inline void gn(long long& x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
inline void gn(int& x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(unsigned long long& x) {
  long long t;
  gn(t);
  x = t;
}
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
long long powmod(long long a, long long x, long long mod) {
  long long t = 1ll;
  while (x) {
    if (x & 1) t = t * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return t;
}
int dp[88][88][88][88];
int cost[99][99];
vector<int> E[99];
int main() {
  memset(dp, 0x3f, sizeof(dp));
  memset(cost, 0x3f, sizeof(cost));
  int n, kk;
  gn(n);
  gn(kk);
  if (kk == 1) {
    puts("0");
    return 0;
  }
  int m;
  gn(m);
  for (int i = (1); i <= (m); i++) {
    int foo, bar, c;
    gn(foo);
    gn(bar);
    gn(c);
    E[foo].push_back(bar);
    cost[foo][bar] = min(cost[foo][bar], c);
    if (foo < bar) {
      dp[2][bar][min(foo, bar) + 1][n] =
          min(dp[2][bar][min(foo, bar) + 1][n], c);
    } else {
      dp[2][bar][1][max(foo, bar) - 1] =
          min(dp[2][bar][1][max(foo, bar) - 1], c);
    }
  }
  for (int i = (2); i <= (kk - 1); i++) {
    for (int j = (1); j <= (n); j++) {
      for (int k = (1); k <= (n); k++) {
        for (int l = (1); l <= (n); l++) {
          if (dp[i][j][k][l] >= 10000) continue;
          for (auto it : E[j]) {
            if (it >= k && it <= l) {
              if (it < j) {
                dp[i + 1][it][k][j - 1] =
                    min(dp[i + 1][it][k][j - 1], dp[i][j][k][l] + cost[j][it]);
              } else {
                dp[i + 1][it][j + 1][l] =
                    min(dp[i + 1][it][j + 1][l], dp[i][j][k][l] + cost[j][it]);
              }
            }
          }
        }
      }
    }
  }
  int ans = inf;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      for (int k = (j); k <= (n); k++) ans = min(ans, dp[kk][i][j][k]);
  if (ans == inf) ans = -1;
  cout << ans << endl;
  return 0;
}
