#include <bits/stdc++.h>
using namespace std;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-9;
const int maxn = 2e5 + 5;
const double pi = acos(-1);
const int N = 2e5 + 6;
int n, m;
long long k;
pair<double, double> a[N];
int pos[N], sum[N];
double dis(const pair<double, double> &a) {
  return a.first * a.first + a.second * a.second;
}
bool cmp(const pair<double, double> &a, const pair<double, double> &b) {
  return dis(a) < dis(b);
}
void add(int x, int d) {
  for (int i = x; i <= m; i += i & (-i)) sum[i] += d;
}
int qry(int x) {
  int res = 0;
  for (int i = x; i > 0; i -= i & (-i)) res += sum[i];
  return res;
}
double dx[N];
long long solve(double r) {
  long long res = 0;
  vector<pair<double, int> > v;
  for (int i = (1); i < (n + 1); i++)
    if (dx[i] * dx[i] > r * r) {
      double d = acos(r / dx[i]);
      double p = atan2(a[i].second, a[i].first);
      double x = p - d;
      double y = p + d;
      if (x + pi < -eps) x += 2 * pi;
      if (y - pi >= -eps) y -= 2 * pi;
      if (x - y > eps) swap(x, y);
      v.push_back(make_pair(x, -i));
      v.push_back(make_pair(y, i));
    }
  sort(v.begin(), v.end());
  for (int i = (1); i < (m + 1); i++) sum[i] = 0;
  for (int i = (1); i < (n + 1); i++) pos[i] = 0;
  int cnt = 0;
  for (int i = (0); i < ((int)v.size()); i++) {
    if (!i || abs(v[i].first - v[i - 1].first) > eps) cnt++;
    if (v[i].second < 0) {
      int x = -v[i].second;
      pos[x] = cnt;
      add(pos[x], 1);
    } else {
      int x = v[i].second;
      res += qry(cnt) - qry(pos[x] - 1) - 1;
      add(pos[x], -1);
    }
  }
  res = 1ll * n * (n - 1) / 2 - res;
  return res;
}
int main() {
  scanf("%d%lld", &n, &k);
  m = 2 * n;
  for (int i = (1); i < (n + 1); i++)
    scanf("%lf%lf", &a[i].first, &a[i].second);
  sort(a + 1, a + n + 1, cmp);
  for (int i = (1); i < (n + 1); i++) dx[i] = sqrt(dis(a[i]));
  double l = 0, r = 2e8;
  for (int j = (0); j < (50); j++) {
    double mid = (l + r) / 2;
    if (solve(mid) >= k)
      r = mid;
    else
      l = mid;
  }
  printf("%.10f", r);
  return 0;
}
