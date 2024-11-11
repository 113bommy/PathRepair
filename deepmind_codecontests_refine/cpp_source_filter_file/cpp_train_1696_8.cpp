#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long double eps = 1e-5;
class Tournament {
  int offset;
  vector<int> cnt;

 public:
  Tournament(int n) {
    for (offset = 1; offset < n; offset *= 2)
      ;
    cnt.resize(2 * offset);
  }
  void update(int x) {
    for (x += offset; x; x /= 2) cnt[x]++;
  }
  long long query(int x, int lo, int hi, int from, int to) const {
    if (lo >= to || hi <= from) return 0;
    if (lo >= from && hi <= to) return cnt[x];
    int mid = (lo + hi) / 2;
    return query(2 * x, lo, mid, from, to) +
           query(2 * x + 1, mid, hi, from, to);
  }
  int query(int from, int to) const { return query(1, 0, offset, from, to); }
};
long long K;
int N;
vector<pair<long double, long double> > pts;
pair<long double, long double> line[MAXN];
void load() {
  scanf("%d%lld", &N, &K);
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x || y)
      pts.push_back({x, y});
    else
      K -= N - 1;
  }
}
long long calc(long double r) {
  vector<long double> all;
  vector<pair<long double, long double> > events;
  auto intersect = [&](long double a, long double b) {
    long double A = a * a + 1;
    long double B = 2 * a * b;
    long double C = b * b - r * r;
    long double D = B * B - 4 * A * C;
    if (D < 0) return;
    long double x1 = (-B + sqrt(D)) / (2 * A);
    long double x2 = (-B - sqrt(D)) / (2 * A);
    long double alpha1 = atan2(a * x1 + b, x1);
    long double alpha2 = atan2(a * x2 + b, x2);
    if (alpha1 > alpha2) swap(alpha1, alpha2);
    events.push_back({alpha1, alpha2});
    all.push_back(alpha1);
    all.push_back(alpha2);
  };
  for (int i = 0; i < N; i++) intersect(line[i].first, line[i].second);
  sort(all.begin(), all.end());
  auto compress = [&](long double &ref) {
    ref = lower_bound(all.begin(), all.end(), ref) - all.begin();
  };
  for (auto &it : events) {
    compress(it.first);
    compress(it.second);
    it.second *= -1;
  }
  long long res = 0;
  sort(events.begin(), events.end());
  Tournament T(all.size());
  for (auto it : events) {
    res += T.query(it.first, -it.second + 1);
    T.update(-it.second);
  }
  return res;
}
long double solve() {
  if (K <= 0) return 0;
  N = pts.size();
  K = (long long)N * (N - 1) / 2 - K + 1;
  for (auto &it : pts) {
    complex<long double> tmp(it.first, it.second);
    tmp *= polar((long double)1, eps);
    it = {tmp.real(), tmp.imag()};
  }
  for (int i = 0; i < N; i++)
    line[i] = {-pts[i].first / pts[i].second, 1 / pts[i].second};
  long double lo = 0, hi = 1e6;
  for (int it = 0; it < 50; it++) {
    long double mid = (lo + hi) / 2;
    if (calc(mid) < K)
      lo = mid;
    else
      hi = mid;
  }
  return 1 / lo;
}
int main() {
  load();
  printf("%.10Lf\n", solve());
  return 0;
}
