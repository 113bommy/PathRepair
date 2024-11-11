#include <bits/stdc++.h>
using namespace std;
long double w, h;
long double alpha;
const long double PI = acos(-1);
struct Line {
  long double a, b;
};
long double csc(long double x) { return (long double)1 / cos(x); }
long double sec(long double x) { return (long double)1 / sin(x); }
Line line[4];
bool isVaild(pair<long double, long double> point) {
  long double x = point.first;
  long double y = point.second;
  return !(x > w / 2 || x < -w / 2 || y > h / 2 || y < -h / 2);
}
void solve() {
  long double res = w * h;
  if (w < h) swap(w, h);
  if (alpha == 90) {
    cout << setprecision(20) << h * h << endl;
  } else if (alpha == 180 || alpha == 0) {
    cout << setprecision(20) << res << endl;
  } else {
    if (alpha > 90) alpha = 180 - alpha;
    long double rad = alpha / 180 * PI;
    long double a = tan(rad);
    long double b = csc(rad) * h / 2;
    pair<long double, long double> pa =
        pair<long double, long double>((h / 2 - b) / a, h / 2);
    pair<long double, long double> pb =
        pair<long double, long double>(-w / 2, -a * w / 2 + b);
    if (!isVaild(pb)) {
      pb = pair<long double, long double>((-h / 2 - b) / a, -h / 2);
      res -= (pa.first - (-w / 2) + pb.first - (-w / 2)) * h;
      cout << setprecision(20) << res << endl;
    } else {
      a = -1 / a;
      b = sec(rad) * w / 2;
      pair<long double, long double> pc =
          pair<long double, long double>((h / 2 - b) / a, h / 2);
      pair<long double, long double> pd =
          pair<long double, long double>(w / 2, a * w / 2 + b);
      res -= (pa.first - (-w / 2)) * (h / 2 - pb.second);
      res -= (w / 2 - pc.first) * (h / 2 - pd.second);
      cout << setprecision(20) << res << endl;
    }
  }
}
int main() {
  cin >> w >> h >> alpha;
  solve();
}
