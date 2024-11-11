#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  long long answer = 0;
  for (long long v = 0; v * v <= n; ++v) {
    long long k1 = v;
    long long k2 = k - k1;
    if (k2 >= 0 && k2 < m && k1 < n) {
      long long t = (n / (k1 + 1)) * (m / (k2 + 1));
      answer = max(answer, t);
    }
    if (v > 0) {
      long long k1 = min(n / v - 1, k);
      long long k2 = k - k1;
      if (0 <= k1 && k1 < n && 0 <= k2 && k2 < m) {
        long long t = (n / (k1 + 1)) * (m / (k2 + 1));
        answer = max(answer, t);
      }
    }
  }
  if (answer == 0) answer = -1;
  cout << answer << '\n';
  return 0;
}
