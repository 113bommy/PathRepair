#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
const long long INF = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long x, y, z;
  long long x1, y1, z1;
  cin >> x >> y >> z >> x1 >> y1 >> z1;
  long long crd[6];
  for (long long i = 0; i < 6; i++) cin >> crd[i];
  long long res = 0;
  if (y < 0) res += crd[0];
  if (y > y1) res += crd[1];
  if (z < 0) res += crd[2];
  if (z > z1) res += crd[3];
  if (x < 0) res += crd[4];
  if (x > x1) res += crd[5];
  cout << res << "\n";
}
