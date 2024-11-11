#include <bits/stdc++.h>
const long long INF = 1e18;
const long long mx = -1e9;
const long long mn = 1e9;
const long long mv = 1e5 + 5;
const double pi = 3.1415926535;
using namespace std;
long long n, x, y, a[mv], ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (x > y) {
    ans = n;
  } else {
    for (int i = 1; i <= n; i++) {
      if (x > a[i]) {
        ans++;
      }
    }
    ans = ans / 2 + ans % 2;
  }
  cout << ans;
}
