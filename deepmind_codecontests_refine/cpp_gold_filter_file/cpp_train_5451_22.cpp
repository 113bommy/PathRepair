#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int32_t main() {
  long long x, y, z;
  cin >> x >> y >> z;
  long long a, b, c;
  cin >> a >> b >> c;
  vector<long long> v(7);
  for (long long i = 1; i <= 6; i++) cin >> v[i];
  long long s = 0;
  if (x < 0) {
    s += v[5];
  } else if (x > a) {
    s += v[6];
  }
  if (y < 0) {
    s += v[1];
  } else if (y > b) {
    s += v[2];
  }
  if (z < 0) {
    s += v[3];
  } else if (z > c) {
    s += v[4];
  }
  cout << s << endl;
}
