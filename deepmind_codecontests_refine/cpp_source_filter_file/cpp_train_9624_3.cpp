#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans = 0;
int main() {
  cin >> n >> m >> k;
  if (n - 1 + m - 1 < k) {
    cout << -1 << endl;
    return 0;
  }
  long long buf = sqrt(k);
  buf++;
  for (int i = 0; i <= buf; i++) {
    long long x = n / (i + 1);
    if (k - i < 0) continue;
    long long y = m / (k - i + 1);
    ans = max(ans, x * y);
  }
  for (int i = 1; i <= buf; i++) {
    long long cut = n / i - 1;
    if (cut < 0) continue;
    long long left = k - cut;
    if (left < 0) left = 0;
    ans = max(ans, i * (m / (left + 1)));
  }
  cout << ans << endl;
  return 0;
}
