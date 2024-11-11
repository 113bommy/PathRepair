#include <bits/stdc++.h>
using namespace std;
int s, x1, x2, t1, t2, p, d;
int result;
int main() {
  int w;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
  if (t1 >= t2)
    result = abs(x2 - x1) * t2;
  else {
    if ((x1 < x2) && (d == 1) && (p > x1))
      w = s - p + s + x1;
    else if ((x1 < x2) && (d == 1) && (p <= x1))
      w = x1 - p;
    else if ((x1 < x2) && (d == -1))
      w = p + x1;
    else if ((x1 > x2) && (d == 1))
      w = s - p + s - x1;
    else if ((x1 > x2) && (d == -1) && (p >= x1))
      w = p - x1;
    else
      w = p + x1;
    result = min((abs(x2 - x1) * t2), (t1 * (w + abs(x1 - x2))));
  }
  cout << result << "\n";
  return 0;
}
