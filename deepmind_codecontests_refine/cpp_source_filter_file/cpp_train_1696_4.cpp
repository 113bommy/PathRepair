#include <bits/stdc++.h>
using namespace std;
struct pnt {
  double x;
  double y;
};
double pi = 3.14159265359;
vector<pnt> v;
double dis(pnt a, pnt b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int n;
pair<double, double> tg(pnt x, double r) {
  double a0, alfa;
  pnt p0 = {0, 0};
  double l = dis(p0, x);
  alfa = acos(r / l);
  a0 = acos(x.x / l);
  if (x.y < 0) a0 = pi + pi - a0;
  double a1 = a0 - alfa;
  double a2 = a0 + alfa;
  if (a1 < 0) a1 += pi + pi;
  if (a1 > pi + pi) a1 -= pi + pi;
  if (a2 < 0) a2 += pi + pi;
  if (a2 > pi + pi) a2 -= pi + pi;
  if (a1 > a2) swap(a1, a2);
  return {a1, a2};
}
double eps = 1e-9;
long long fn[400009];
long long get(int x) {
  x++;
  long long t = 0;
  while (x < 400009) {
    t += fn[x];
    x += (x & (-x));
  }
  return t;
}
void add(int x) {
  while (x > 0) {
    fn[x]++;
    x -= (x & (-x));
  }
  return;
}
void dec(int x) {
  while (x > 0) {
    fn[x]--;
    x -= (x & (-x));
  }
  return;
}
long long f(double r) {
  vector<pair<double, int>> pl;
  for (int i = 0; i < 400009; i++) fn[i] = 0;
  vector<pair<double, double>> tt;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    pair<double, double> pp;
    if (dis(v[i], {0.0, 0.0}) > r) pp = tg(v[i], r);
    if (pp.second - pp.first > 0) tt.push_back(pp);
  }
  sort(tt.begin(), tt.end());
  for (int i = 0; i < tt.size(); i++) {
    pl.push_back({tt[i].first, -i - 1});
    pl.push_back({tt[i].second, i + 1});
  }
  sort(pl.begin(), pl.end());
  for (int i = 0; i < pl.size(); i++) {
    if (pl[i].second > 0) {
      ans += get(pl[i].second);
      dec(pl[i].second);
    } else {
      add(-pl[i].second);
    }
  }
  return n * (n - 1) / 2 - ans;
}
double solve(long long k) {
  double l = 0, r = 20000;
  while (fabs(l - r) > eps) {
    double mid = (l + r) / 2;
    long long g = f(mid);
    if (g > k)
      r = mid;
    else
      l = mid;
  }
  return l;
}
int main() {
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    pnt c;
    cin >> c.x >> c.y;
    v.push_back(c);
  }
  f(1);
  printf("%12f", solve(k - 1));
}
