#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 200;
void chap() { cout << "-1\n"; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  if (k == 1 || k > 3) return cout << "-1\n", 0;
  if (k == 2) {
    if (n < 4) return chap(), 0;
    cout << n - 1 << "\n";
    for (long long i = 1; i < n; i++) cout << i << " " << i + 1 << "\n";
  } else if (k == 3) {
    if (n < 4) return chap(), 0;
    cout << n - 1 << "\n";
    cout << "1 2\n2 3\n3 4\n";
    for (long long i = 5; i <= n; i++) cout << 3 << " " << i << "\n";
  }
  return 0;
}
