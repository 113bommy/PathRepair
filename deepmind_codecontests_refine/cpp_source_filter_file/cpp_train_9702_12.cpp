#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, x1, x2, y1, y2, r1, r2, s1, s2, d1, d2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  s1 = x1 + y1;
  d1 = x1 - y1;
  s2 = x2 + y2;
  d2 = x2 - y2;
  if (s1 < s2)
    r1 = (s1) % (2 * a);
  else
    r1 = (s2) % (2 * a);
  if (d1 < d2)
    r2 = (d1) % (2 * b);
  else
    r2 = (d2) % (2 * b);
  if (r1 < 0) r1 = 2 * a - r1;
  if (r2 < 0) r2 = 2 * b - r2;
  cout << max(((long long)abs(s1 - s2) + r1) / (2 * a),
              ((long long)abs(d1 - d2) + r2) / (2 * b));
}
