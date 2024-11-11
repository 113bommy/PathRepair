#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n;
double l, r, a, b;
double x[N];
double y[N];
double vx[N];
double vy[N];
double inf = 1e18;
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  cin >> n;
  cin >> l >> a >> r >> b;
  if (l > r) swap(l, r);
  if (a > b) swap(a, b);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> vx[i] >> vy[i];
  vector<pair<double, double> > p;
  for (int i = 0; i < n; i++) {
    double q1 = inf, q2 = -inf, w1 = inf, w2 = -inf;
    if (vx[i] == 0 && x[i] > l && x[i] < r) {
      q1 = 0;
      q2 = inf;
    }
    if (vx[i] > 0 && x[i] < r) {
      q1 = max((double)0, (l - x[i]) / vx[i]);
      q2 = (r - x[i]) / vx[i];
    }
    if (vx[i] < 0 && x[i] > l) {
      q1 = max((double)0, (r - x[i]) / vx[i]);
      q2 = (l - x[i]) / vx[i];
    }
    if (vy[i] == 0 && y[i] > a && y[i] < b) {
      w1 = 0;
      w2 = inf;
    }
    if (vy[i] > 0 && y[i] < b) {
      w1 = max((double)0, (a - y[i]) / vy[i]);
      w2 = (b - y[i]) / vy[i];
    }
    if (vy[i] < 0 && y[i] > a) {
      w1 = max((double)0, (b - y[i]) / vy[i]);
      w2 = (a - y[i]) / vy[i];
    }
    double q = max(q1, w1);
    double w = min(q2, w2);
    if (q < w) p.push_back(make_pair(q, w));
  }
  sort(p.begin(), p.end());
  double mn = inf;
  for (int i = 0; i < p.size(); i++) {
    if (mn < p[i].first) {
      cout << "-1\n";
      return 0;
    }
    mn = min(mn, p[i].second);
  }
  if (p.size() != n)
    cout << "-1\n";
  else
    cout << p[p.size() - 1].first << endl;
  return 0;
}
