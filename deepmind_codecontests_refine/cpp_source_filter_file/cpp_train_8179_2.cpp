#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const double eps = 1e-6;
int n, m, k;
double T, t[maxn], g[maxn];
pair<int, int> a[maxn];
struct node {
  double l, r;
  int first, second;
  node(double a = 0, double b = 0, int c = 0, int d = 0) {
    l = a;
    r = b;
    first = c;
    second = d;
  }
} f[maxn];
struct data {
  double k, b;
  data(double first = 0, double second = 0) {
    k = first;
    b = second;
  }
} A[maxn], B[maxn];
map<double, int> Map;
inline double sqr(double first) { return first * first; }
inline double Dis(pair<int, int> a, pair<int, int> b) {
  return sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}
inline double Get(double a, double b, double c, double first) {
  return a * first * first + b * first + c;
}
inline data get(pair<double, double> a, pair<double, double> b) {
  double k = (a.second - b.second) / (a.first - b.first);
  return data(k, a.second - k * a.first);
}
inline data operator-(data a, data b) { return data(a.k - b.k, a.b - b.b); }
inline bool Check(double first) {
  Map.clear();
  vector<pair<double, double> > p;
  for (int i = (1), _end_ = (k); i <= _end_; ++i) {
    data l1 = data(A[f[i].first] - A[f[i].second]);
    l1.b -= T * A[f[i].second].k;
    data l2 = data(B[f[i].first] - B[f[i].second]);
    l2.b -= T * B[f[i].second].k;
    double a = l1.k * l1.k + l2.k * l2.k;
    double b = 2 * l1.k * l1.b + 2 * l2.k * l2.b;
    double c = l1.b * l1.b + l2.b * l2.b - first * first;
    double x1, x2;
    if (!a && !b) {
      if (c > 0) continue;
      x1 = f[i].l;
      x2 = f[i].r;
    } else if (!a)
      x1 = x2 = -b / c;
    else {
      double delta = b * b - 4 * a * c;
      if (delta < 0) continue;
      delta = sqrt(delta);
      x1 = (delta - b) / a / 2;
      x2 = (-delta - b) / a / 2;
    }
    if (x1 > x2) swap(x1, x2);
    x1 = max(f[i].l, x1);
    x2 = min(f[i].r, x2);
    if (x1 > x2 + eps) continue;
    if (x2 - x1 >= T - eps) {
      Map[0] += (int)((x2 - x1) / T);
      Map[T + eps] -= (int)((x2 - x1) / T);
      x1 = x1 + (int)((x2 - x1) / T) * T;
    }
    x1 = x1 - (int)(x1 / T) * T;
    x2 = x2 - (int)(x2 / T) * T;
    if (x1 < x2 + eps)
      p.push_back(pair<double, double>(x1, x2));
    else {
      p.push_back(pair<double, double>(x1, T));
      p.push_back(pair<double, double>(0, x2));
    }
  }
  for (auto it : p) {
    ++Map[it.first];
    --Map[it.second + eps];
  }
  int sum = 0;
  for (auto it : Map) {
    sum += it.second;
    if (sum >= m) return true;
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1), _end_ = (n); i <= _end_; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    a[n + i] = a[i];
  }
  for (int i = (1), _end_ = (n + n); i <= _end_; ++i) {
    t[i] = Dis(a[i], a[i + 1]);
    g[i] = g[i - 1] + t[i];
    A[i] = get(pair<double, double>(g[i - 1], a[i].first),
               pair<double, double>(g[i], a[i + 1].first));
    B[i] = get(pair<double, double>(g[i - 1], a[i].second),
               pair<double, double>(g[i], a[i + 1].second));
  }
  T = g[n] / m;
  int pos = 1;
  while (g[pos] < T) ++pos;
  double lst = T - g[pos - 1];
  for (int i = (1), _end_ = (n); i <= _end_; ++i) {
    double first = g[i - 1];
    while (g[i] + T > g[pos]) {
      f[++k] = node(first, first + t[pos] - lst - 0.01, i, pos);
      first += t[pos] - lst;
      lst = 0;
      ++pos;
    }
    f[++k] = node(first, g[i] - 0.01, i, pos);
    lst = g[i] + T - g[pos - 1];
  }
  double l = 0, r = T;
  for (int o = (1), _end_ = (65); o <= _end_; ++o) {
    double Mid = (l + r) / 2.0;
    if (Check(Mid))
      r = Mid;
    else
      l = Mid;
  }
  printf("%.6lf\n", (l + r) / 2.0);
  return 0;
}
