#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e7 + 123;
long long arr[MX];
long long brr[MX];
long long crr[MX];
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << '\n';
    } else if (n % 3 == 1) {
      cout << n / 3 + 1 << " " << n / 3 << '\n';
    } else if (n % 3 == 2) {
      cout << n / 3 << " " << n / 3 + 2 << '\n';
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
