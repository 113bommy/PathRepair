#include <bits/stdc++.h>
using namespace std;
void Main() {
  int N;
  double w, v, u;
  cin >> N >> w >> v >> u;
  vector<pair<int, int> > ps(N);
  bool ok1 = 1;
  bool ok2 = 1;
  double dmax = 0;
  for (int i = int(0); i < int(N); ++i) {
    int x, y;
    cin >> x >> y;
    ps[i] = {x, y};
    {
      double t = y / u;
      double xx = t * v;
      if (xx > x) {
        ok1 = 0;
      }
      if (xx < x) {
        ok2 = 0;
      }
      dmax = max(dmax, x - xx);
    }
  }
  double t0 = w / u;
  if (ok1 || ok2) {
    (void)printf("%.10f\n", t0);
    return;
  }
  double ans = t0 + dmax / v;
  (void)printf("%.10f\n", ans);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Main();
  return 0;
}
