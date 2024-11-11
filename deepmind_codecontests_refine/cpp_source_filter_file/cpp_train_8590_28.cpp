#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1>
T maxn(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T minn(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
void solve() {
  long long int n, d, h, u = 1, v = 2, height = 0;
  cin >> n >> d >> h;
  if (d == 1 && h == 1 && n == 2)
    cout << "1 2"
         << "\n";
  else if (d > 1 && n >= d + 1 && d <= (2 * h)) {
    while (++height <= h) cout << u++ << " " << v++ << "\n";
    u = 1;
    while (height++ <= d) {
      cout << u << " " << v << "\n";
      u = v++;
    }
    if (h > 1 && h != d)
      u = 1;
    else
      u = 2;
    while (v <= n) cout << u << " " << v++ << "\n";
  } else
    cout << "-1"
         << "\n";
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int testcase = 1;
  while (testcase--) solve();
  return 0;
}
