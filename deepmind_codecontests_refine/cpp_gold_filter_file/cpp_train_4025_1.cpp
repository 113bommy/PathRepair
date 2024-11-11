#include <bits/stdc++.h>
using namespace std;
int main() {
  int hh, mm, h, d, c, n;
  double ans1, ans2;
  cin >> hh >> mm >> h >> d >> c >> n;
  if (hh >= 20) {
    if (h % n == 0)
      cout << fixed << setprecision(3) << h / n * c * .80;
    else
      cout << fixed << setprecision(3) << (h / n + 1) * c * .80 << endl;
  } else {
    int t = ((19 - hh) * 60) + 60 - mm;
    if (h % n == 0) {
      ans1 = h / n * c;
      if ((h + d * t) % n == 0)
        ans2 = (h + d * t) / n * c * .80;
      else
        ans2 = ((h + d * t) / n + 1) * c * .80;
    } else {
      ans1 = (h / n + 1) * c;
      if ((h + d * t) % n == 0)
        ans2 = (h + d * t) / n * c * .80;
      else
        ans2 = ((h + d * t) / n + 1) * c * .80;
    }
    cout << fixed << setprecision(3) << min(ans1, ans2) << endl;
  }
  return 0;
}
