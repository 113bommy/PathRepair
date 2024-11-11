#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, xmax, xmin, ymax, ymin, t1, t2;
  long long ans;
  int n;
  cin >> n;
  cin >> t1 >> t2;
  xmax = t1;
  xmin = t1;
  ymax = t2;
  ymin = t2;
  for (i = 1; i < n; i++) {
    cin >> t1 >> t2;
    xmax = (t1 > xmax ? t1 : xmax);
    xmin = (t1 < xmin ? t1 : xmin);
    ymax = (t2 > ymax ? t2 : ymax);
    ymin = (t2 < ymin ? t2 : ymin);
  }
  ans = ((xmax - xmin) > (ymax - ymin) ? (xmax - xmin) * (xmax - xmin)
                                       : (ymax - ymin) * (ymax - ymin));
  cout << ans << "\n";
  return 0;
}
