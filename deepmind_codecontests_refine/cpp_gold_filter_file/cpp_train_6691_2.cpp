#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int T, n, a[N], sum;
inline void solve() {
  sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i];
  if (sum % n) {
    cout << -1 << endl;
    return;
  }
  sum /= n;
  cout << 3 * (n - 1) << endl;
  for (int i = 2; i <= n; i++) {
    int rem = a[i] % i;
    cout << 1 << " " << i << " " << (i - rem) % i << endl;
    a[1] -= (i - rem) % i;
    a[i] += (i - rem) % i;
    cout << i << " " << 1 << " " << a[i] / i << endl;
    a[1] += a[i];
    a[i] = 0;
  }
  for (int i = 2; i <= n; i++) cout << 1 << " " << i << " " << sum << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    solve();
  }
  return 0;
}
