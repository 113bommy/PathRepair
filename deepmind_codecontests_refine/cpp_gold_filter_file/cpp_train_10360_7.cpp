#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
const double eps = 1e-9;
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') f = 1, c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
struct FEN {
  int x[MX];
  FEN() { memset(x, 0, sizeof(x)); }
  void add(int p, int v) {
    for (int i = p + 1; i < MX; i += i & -i) x[i] += v;
  }
  int qur(int p) {
    int ret = 0;
    for (int i = p + 1; i; i -= i & -i) ret += x[i];
    return ret;
  }
};
template <typename T>
struct NODE {
  int id;
  T l, r;
  NODE(const int &i0 = 0, const T &l0 = 0, const T &r0 = 0)
      : id(i0), l(l0), r(r0) {}
  bool operator<(const NODE &t) const {
    return (l != t.l) ? (l < t.l) : (r < t.r);
  }
};
struct vec {
  double x, y;
  vec(const double &x0 = 0, const double &y0 = 0) : x(x0), y(y0) {}
  vec operator+(const vec &t) const { return vec(x + t.x, y + t.y); }
  vec operator-(const vec &t) const { return vec(x - t.x, y - t.y); }
  vec operator*(const double &t) const { return vec(x * t, y * t); }
  double len2() const { return x * x + y * y; }
  double ang() const { return atan2(y, x); }
};
double dot(const vec &a, const vec &b) { return a.x * b.x + a.y * b.y; }
double crs(const vec &a, const vec &b) { return a.x * b.y - a.y * b.x; }
bool check_lin_cir_int(vec o, double r, vec p, vec v) {
  double a = dot(v, v);
  double b = 2 * dot(p - o, v);
  double c = dot(p - o, p - o) - r * r;
  double delta = b * b - 4 * a * c;
  return (delta > 0);
}
pair<vec, vec> lin_cir_int(vec o, double r, vec p, vec v) {
  double a = dot(v, v);
  double b = 2 * dot(p - o, v);
  double c = dot(p - o, p - o) - r * r;
  double delta = b * b - 4 * a * c;
  double k1 = (-b + sqrt(delta)) / (2 * a);
  double k2 = (-b - sqrt(delta)) / (2 * a);
  return make_pair(p + v * k1, p + v * k2);
}
vec lin_lin_int(vec p1, vec v1, vec p2, vec v2) {
  double k = crs(p2 - p1, v2) / crs(v1, v2);
  return p1 + v1 * k;
}
int n, m;
vec cen;
vec pi[MX], vi[MX];
void input() {
  read(n);
  int x, y;
  read(x), read(y), read(m);
  cen = vec(x / 1000.0, y / 1000.0);
  for (int i = 1; i <= n; i++) {
    read(x), read(y);
    pi[i] = vec(0, y / 1000.0);
    vi[i] = vec(1, x / 1000.0);
  }
}
vector<NODE<int> > get_seg(double rad) {
  vector<NODE<double> > seg_r;
  vector<NODE<int> > seg_i;
  vector<double> rel;
  for (int i = 1; i <= n; i++) {
    if (check_lin_cir_int(cen, rad, pi[i], vi[i])) {
      auto its = lin_cir_int(cen, rad, pi[i], vi[i]);
      auto tmp =
          NODE<double>(i, (its.first - cen).ang(), (its.second - cen).ang());
      if (tmp.l > tmp.r) swap(tmp.l, tmp.r);
      seg_r.emplace_back(tmp);
    }
  }
  for (auto i : seg_r) rel.emplace_back(i.l), rel.emplace_back(i.r);
  sort(rel.begin(), rel.end());
  rel.erase(unique(rel.begin(), rel.end()), rel.end());
  auto fake = [=](double x) {
    return lower_bound(rel.begin(), rel.end(), x) - rel.begin() + 1;
  };
  for (auto i : seg_r)
    seg_i.emplace_back(NODE<int>(i.id, fake(i.l), fake(i.r)));
  sort(seg_i.begin(), seg_i.end());
  return seg_i;
}
int count_int(double rad) {
  FEN fen;
  int ret = 0;
  auto seg_i = get_seg(rad);
  for (auto i : seg_i)
    ret = min(m + 10, ret + fen.qur(i.r) - fen.qur(i.l)), fen.add(i.r, 1);
  return ret;
}
pair<double, int> calc_sum(double rad) {
  int cnt = 0;
  double ret = 0;
  auto seg_i = get_seg(rad);
  set<pair<int, int> > st;
  for (auto i : seg_i) {
    for (auto it = st.upper_bound(make_pair(i.l, MX));
         it != st.end() && it->first <= i.r; it++) {
      int a = it->second, b = i.id;
      ret += sqrt((lin_lin_int(pi[a], vi[a], pi[b], vi[b]) - cen).len2());
      cnt++;
      if (cnt >= m) return make_pair(ret, cnt);
    }
    st.insert(make_pair(i.r, i.id));
  }
  return make_pair(ret, cnt);
}
void work() {
  double l = 0, r = 1e20, mid;
  for (int i = 0; i < 100; i++) {
    mid = (l + r) / 2.0;
    if (count_int(mid) >= m)
      r = mid;
    else
      l = mid;
  }
  double rad = l;
  auto tmp = calc_sum(rad);
  printf("%.8lf\n", tmp.first + (m - tmp.second) * rad);
}
int main() {
  input();
  work();
  return 0;
}
