#include <bits/stdc++.h>
using namespace std;
int k, x, y;
long long h, m;
long long h1, m1, h2, m2;
long long res1, res2;
int calc0(int x) {
  int k = 0;
  while (x) {
    if (x % 10 > 0) k++;
    x /= 10;
  }
  return k;
}
long long solve(long long hx, long long mx) {
  long long t1 = 1;
  for (int i = 1; i <= k - 1; i++) {
    t1 *= 10;
    if (t1 > 1e10) break;
  }
  long long t2 = 1;
  for (int i = 1; i <= max(0, k - y - 1); i++) {
    t2 *= 10;
    if (t2 > 1e10) break;
  }
  long long ans = hx * ((m - 1) / t1) + mx / t1 + hx / t2;
  return ans;
}
int main() {
  cin >> h >> m >> k;
  cin >> h1 >> m1;
  cin >> h2 >> m2;
  x = calc0(h - 1);
  y = calc0(m - 1);
  res1 = solve(h1, m1);
  if (h2 > h1 || (h2 == h1 && m2 > m1))
    res2 = solve(h2, m2);
  else {
    res2 = solve(h - 1, m - 1) + solve(h2, m2);
    if (x + y >= k) res2++;
  }
  cout << res2 - res1 << endl;
}
