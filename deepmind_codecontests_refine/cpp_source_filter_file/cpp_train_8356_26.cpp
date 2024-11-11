#include <bits/stdc++.h>
#pragma GCC optimze("02")
using namespace std;
using ll = long long;
const ll N = 2e5 + 5, inf = 1e18 + 18;
ll n, m, t;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << ' ' << 0 << ' ' << 0 << endl;
      continue;
    }
    if (n % 5 == 0) {
      cout << 0 << ' ' << n / 5 << ' ' << 0 << endl;
      continue;
    }
    if (n % 7 == 0) {
      cout << 0 << ' ' << 0 << ' ' << n / 7 << endl;
      continue;
    }
    if (n < 7) {
      cout << -1 << endl;
      continue;
    }
    if (n % 3 == 1) {
      cout << (n - 7) / 3 << ' ' << 0 << ' ' << 1 << endl;
    }
    cout << (n - 2) / 3 << ' ' << 1 << ' ' << 0 << endl;
  }
}
