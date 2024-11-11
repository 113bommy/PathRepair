#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long c[N], p[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> c[i];
  long long ans = 0;
  for (long long k = 1; k * n <= m; k++) {
    p[n - 1] = m * k - (k - 1) * k / 2 * n;
    p[n - 1] = min(p[n - 1], c[n - 1]);
    for (int i = n - 2; i >= 0; i--) p[i] = min(p[i + 1] - k, c[i]);
    if (p[0] <= k * (k + 1) / 2LL) break;
    long long space = m - n * k;
    long long out = p[0];
    long long prev = p[0];
    for (int i = 1; i < n; i++) {
      prev = prev + k;
      int shift_size = min(space, p[i] - prev);
      space -= shift_size;
      prev += shift_size;
      out += prev;
    }
    ans = max(ans, out);
  }
  cout << ans << "\n";
  return 0;
}
