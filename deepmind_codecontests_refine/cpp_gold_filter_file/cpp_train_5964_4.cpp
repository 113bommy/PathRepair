#include <bits/stdc++.h>
using namespace std;
const long long MX = 2020;
const long long INF = 1e18;
long long L[MX];
long long R[MX];
long long M[MX];
long long memo[MX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  cout << fixed;
  for (long long i = 0; i < MX; i++) memo[i] = INF;
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> L[i] >> R[i] >> M[i];
  long long bullets, remain, m, l, r;
  for (long long i = 0; i < n; i++) {
    bullets = l = 0;
    remain = k;
    for (long long j = i; j < n; j++) {
      l = max(l, L[j]);
      r = R[j];
      m = M[j];
      if (l > r) break;
      long long mn = min(m, remain);
      m -= mn;
      remain -= mn;
      bullets += mn;
      if (remain == 0 && m > 0) {
        l++;
        long long charges = (m + k - 1) / k;
        if (l > r || charges > r - l + 1) break;
        l += charges - 1;
        remain = k * charges - m;
        bullets += m;
      }
      if (j != n - 1) {
        if (l != L[j + 1] && i != 0)
          memo[j] = min(memo[i - 1] +
                            (memo[i - 1] % k == 0 ? 0 : k - memo[i - 1] % k) +
                            bullets,
                        memo[j]);
        if (l != L[j + 1] && i == 0) memo[j] = bullets;
      } else {
        if (i != 0)
          memo[j] = min(memo[i - 1] +
                            (memo[i - 1] % k == 0 ? 0 : k - memo[i - 1] % k) +
                            bullets,
                        memo[j]);
        if (i == 0) memo[j] = bullets;
      }
    }
  }
  if (memo[n - 1] == INF) {
    cout << -1 << "\n";
  } else {
    cout << memo[n - 1] << "\n";
  }
  return 0;
}
