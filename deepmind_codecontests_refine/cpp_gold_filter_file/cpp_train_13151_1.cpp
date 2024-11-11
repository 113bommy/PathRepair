#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9;
using namespace std;
long long n, a, d, t, v;
double lastT, t1, d1;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> a >> d;
  for (long long i = 0; i < n; ++i) {
    cin >> t >> v;
    d1 = v * v * 1.0 / (2.0 * a);
    t1 = v * 1.0 / a;
    if (d1 <= d) {
      d1 = d - d1;
      t1 += d1 / v;
      t1 += t;
      if (t1 >= lastT) lastT = t1;
    } else {
      t1 = sqrt(2.0 * d / a);
      t1 += t;
      if (t1 >= lastT) lastT = t1;
    }
    cout << fixed << setprecision(10) << lastT << "\n";
  }
  return 0;
}
