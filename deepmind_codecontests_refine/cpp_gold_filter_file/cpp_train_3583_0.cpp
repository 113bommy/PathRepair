#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const long long int INFLL = 1e18 + 10;
const long double EPS = 1e-8;
const long double EPSLD = 1e-14;
const long long int MOD = 1000000007;
template <class T>
T &chmin(T &a, const T &b) {
  return a = min(a, b);
}
template <class T>
T &chmax(T &a, const T &b) {
  return a = max(a, b);
}
const int MAX_N = 128;
int n, m;
int a[MAX_N];
char t[MAX_N];
int p[MAX_N];
int dp[1 << 20][21];
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (int)(n); i++) scanf("%d", &a[i]);
  sort(a, a + n);
  reverse(a, a + n);
  scanf("%d\n", &m);
  for (int i = (0); i < (int)(m); i++) scanf("%c %d\n", &t[i], &p[i]);
  for (int i = m - 1; i >= 0; i--) {
    for (int j = (0); j < (int)(1 << m); j++) {
      if (__builtin_popcount(j) != i) continue;
      if (p[i] == 1) {
        dp[j][i] = -INF;
        for (int k = (0); k < (int)(m); k++)
          if (!(j & (1 << k))) {
            if (t[i] == 'b') chmax(dp[j][i], dp[j | (1 << k)][i + 1]);
            if (t[i] == 'p') chmax(dp[j][i], dp[j | (1 << k)][i + 1] + a[k]);
          }
      } else {
        dp[j][i] = INF;
        for (int k = (0); k < (int)(m); k++)
          if (!(j & (1 << k))) {
            if (t[i] == 'b') chmin(dp[j][i], dp[j | (1 << k)][i + 1]);
            if (t[i] == 'p') chmin(dp[j][i], dp[j | (1 << k)][i + 1] - a[k]);
          }
      }
    }
  }
  printf("%d\n", dp[0][0]);
  return 0;
}
