#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
const long long INF = 1e9 + 7;
long long a, b, m, vx, vy, vz;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> m >> vx >> vy >> vz;
  double time = (double)m / (-vy);
  double x = (double)a / 2 + (double)time * vx;
  double z = time * vz;
  long long cnt = 0;
  while (x >= a) {
    x -= (double)a;
    cnt++;
  }
  while (x <= 0) {
    x += (double)a;
    cnt++;
  }
  if (cnt % 2 == 1) {
    x = (double)b - x;
  }
  long long ctr1 = 0;
  while (z >= b) {
    z -= (double)b;
    ctr1++;
  }
  if (ctr1 % 2 == 1) {
    z = (double)b - z;
  }
  cout << setprecision(10) << x << " " << setprecision(10) << z << "\n";
}
