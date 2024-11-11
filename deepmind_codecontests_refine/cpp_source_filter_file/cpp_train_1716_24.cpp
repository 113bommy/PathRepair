#include <bits/stdc++.h>
using namespace std;
template <typename T, typename L>
bool smax(T& x, L y) {
  return x < y ? x = y, true : false;
}
long long c, wa, wb, ha, hb;
long long mx = -1;
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cerr << "HELLO WORLD :)\n";
  cin >> c >> ha >> hb >> wa >> wb;
  for (long long i = 1; i <= 3e7 && i * wa <= c; i++)
    smax(mx, i * ha + (c - wa * i) / wb * hb);
  for (long long i = 1; i <= 3e7 && i * wb <= c; i++)
    smax(mx, i * hb + (c - wb * i) / wa * ha);
  return cout << (mx == -1 ? 0 : mx) << '\n', false;
}
