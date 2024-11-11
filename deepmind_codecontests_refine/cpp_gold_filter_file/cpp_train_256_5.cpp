#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 100 * 1000 + 10;
const int K = 5 * 1000 + 5;
long long Inf = 1ll * 1000 * 1000 * 1000 * 1000 * 1000;
long long a[N];
long long dp[K][K];
long long ps[N];
long long n;
long long k;
long long c;
void input() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  c = n / k;
  sort(a, a + n);
}
void partialSum() {
  ps[0] = 0;
  ps[1] = 0;
  for (int i = 2; i <= n; i++) ps[i] = ps[i - 1] + a[i - 1] - a[i - 2];
}
long long get(long long l, long long r) { return ps[r] - ps[l]; }
void update(int n, int m) {
  long long ans = Inf;
  dp[n][m] = ans;
  if (n != m) dp[n][m] = dp[n - 1][m] + get((n - 1) * c + m + 1, n * c + m);
  if (m > 0) {
    long long tmp;
    tmp = dp[n - 1][m - 1] + get((n - 1) * c + m, n * c + m);
    dp[n][m] = min(dp[n][m], tmp);
  }
}
void solver() {
  for (int i = 1; i <= k; i++)
    for (int j = 0; j <= n % k; j++) update(i, j);
  cout << dp[k][n % k] << endl;
}
int main() {
  input();
  partialSum();
  solver();
}
