#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MXN = 2e5 + 5;
const long long LMXN = 1e14;
const int MOD = 1e9 + 7;
long long cs = 0;
void solve() {
  int n;
  cin >> n;
  int a[4 * n];
  for (int i = 0; i < (4 * n); i++) cin >> a[i];
  sort(a, a + (4 * n));
  long long x = a[0] * a[4 * n - 1];
  for (int i = 0; i < 4 * n / 2; i += 2) {
    if (a[i] * a[4 * n - i - 1] != x && a[i] == a[i + 1] &&
        a[4 * n - i - 1] == a[4 * n - i - 2]) {
      cout << "NO"
           << "\n";
      return;
    }
  }
  cout << "YES"
       << "\n";
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
