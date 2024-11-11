#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double EPS = 1e-9, INF = 1e12;
const int MX = 100100;
int n;
int a, b, c, d;
int x[MX], y[MX];
int bit[MX];
int sum(int i) {
  int res = 0;
  for (; i; i -= i & -i) res = max(res, bit[i]);
  return res;
}
void add(int i, int x) {
  for (; i < MX; i += i & -i) bit[i] = max(bit[i], x);
}
int main() {
  scanf("%d", &n);
  scanf("%d/%d %d/%d", &a, &b, &c, &d);
  vector<pair<long long, long long> > ps;
  vector<long long> xs;
  for (int i = 0; i < (int)n; i++) {
    scanf("%d%d", x + i, y + i);
    long long xx = (long long)b * y[i] - (long long)a * x[i];
    long long yy = (long long)d * y[i] - (long long)c * x[i];
    ps.push_back(make_pair(yy, xx));
    xs.push_back(xx);
  }
  xs.push_back(0);
  sort(ps.begin(), ps.end());
  sort(xs.begin(), xs.end());
  reverse(ps.begin(), ps.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  int zero = lower_bound(xs.begin(), xs.end(), 0) - xs.begin() + 1;
  for (int i = 0; i < (int)n; i++) {
    int x = lower_bound(xs.begin(), xs.end(), ps[i].second) - xs.begin() + 1;
    if (x <= zero || ps[i].first >= 0) continue;
    add(x + 1, sum(x) + 1);
  }
  cout << sum(n + 1) << endl;
  return 0;
}
