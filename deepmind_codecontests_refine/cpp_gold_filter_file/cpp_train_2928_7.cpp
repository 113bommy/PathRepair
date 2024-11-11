#include <bits/stdc++.h>
using namespace std;
template <typename T>
void vout(T x) {
  cout << x << endl;
  exit(0);
}
int gcd(int a, int b) {
  while (a && b) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
const int inf = 2e9 + 7;
const long long INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2000;
long long n, k, x, a[5100], sp[20][5100], L[5100], dp[5100][5100];
void build(int v) {
  for (int i = 0; i <= n; ++i) sp[0][i] = dp[v][i];
  for (int i = 1; i <= L[n]; ++i) {
    for (int j = 0; j + (1 << i) - 1 <= n; ++j)
      sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + (1 << i) / 2]);
  }
}
long long get(int l, int r) {
  int N = r - l + 1;
  int ln = L[N];
  return max(sp[ln][l], sp[ln][r - (1 << ln) + 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> x;
  for (int i = 2; i <= n; ++i) L[i] = L[i / 2] + 1;
  if (n / k > x) vout(-1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < 5100; ++i) {
    for (int j = 0; j < 5100; ++j) dp[i][j] = -INF;
  }
  dp[0][0] = 0;
  int l, r;
  for (int i = 1; i <= x; ++i) {
    build(i - 1);
    for (int j = 1; j <= n; ++j) {
      l = max(0LL, j - k);
      r = j - 1;
      dp[i][j] = max(dp[i][j], get(l, r) + a[j]);
    }
  }
  long long ans = 0;
  for (int i = n - k + 1; i <= n; ++i) ans = max(ans, dp[x][i]);
  cout << ans << endl;
  return 0;
}
