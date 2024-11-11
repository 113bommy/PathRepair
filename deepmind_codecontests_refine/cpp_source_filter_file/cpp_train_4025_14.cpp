#include <bits/stdc++.h>
const int cnt = 1200;
using namespace std;
int main() {
  double hh, m;
  cin >> hh >> m;
  double h, d, c, n;
  cin >> h >> d >> c >> n;
  double t = hh * 60 + m;
  int last = cnt - t;
  cout << min(ceil(h / n * c), ceil((h + d * max(last, 0)) / n * c * 0.8))
       << endl;
  return 0;
}
