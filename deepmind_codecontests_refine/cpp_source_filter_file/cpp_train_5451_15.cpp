#include <bits/stdc++.h>
using namespace std;
inline long long labs(long long a) { return a < 0 ? (-a) : a; }
template <typename T>
inline T sqr(T x) {
  return x * x;
}
int main() {
  int x, y, z;
  int x1, y1, z1;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;
  vector<int> a(7);
  for (int(i) = 0; (i) < (6); (i)++) cin >> a[i + 1];
  int res = 0;
  if (y > y1) res += a[2];
  if (y < 0) res += a[0];
  if (x > x1) res += a[6];
  if (x < 0) res += a[5];
  if (z > z1) res += a[4];
  if (z < 0) res += a[3];
  cout << res << endl;
  return 0;
}
