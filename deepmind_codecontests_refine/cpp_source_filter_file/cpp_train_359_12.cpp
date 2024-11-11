#include <bits/stdc++.h>
using namespace std;
struct info {
  int s, r, id;
  info(int s = 0, int r = 0, int id = 0) : s(s), r(r), id(id) {}
  bool operator<(const info& b) const {
    if (s != b.s) return s < b.s;
    return r > b.r;
  }
};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long myabs(long long x) { return x > 0 ? x : -x; }
struct fract {
  long long n, d;
  fract(long long num = 0, long long den = 1) {
    assert(0 < den && den < 100000000000000000LL);
    long long g = gcd(myabs(num), myabs(den));
    n = num / g;
    d = den / g;
  }
  fract operator+(const fract& b) const {
    return fract(n * b.d + d * b.n, d * b.d);
  }
  fract operator-(const fract& b) const {
    return fract(n * b.d - d * b.n, d * b.d);
  }
  fract operator*(const fract& b) const { return fract(n * b.n, d * b.d); }
};
struct point {
  fract x, y;
  point(fract x = 0, fract y = 0) : x(x), y(y) {}
  point operator+(const point& b) const { return point(x + b.x, y + b.y); }
  point operator-(const point& b) const { return point(x - b.x, y - b.y); }
  fract cross(const point& b) const { return x * b.y - y * b.x; }
};
bool isConvex(int r1, int s1, int r2, int s2, int r3, int s3) {
  point A(fract(r2 - r1, r2), fract(s2 - s1, s2));
  point B(fract(r3 - r1, r3), fract(s3 - s1, s3));
  return (A.cross(B).n > 0);
}
bool isPositive(int r1, int s1, int r2, int s2) {
  assert(s2 > s1);
  return (r2 - r1) * (s2 - s1) < 0;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<info> runner(n);
  map<pair<int, int>, vector<int> > id;
  for (int i = 0; i < (n); i++) {
    scanf("%d%d", &runner[i].s, &runner[i].r);
    runner[i].id = i + 1;
    id[make_pair(runner[i].s, runner[i].r)].push_back(i + 1);
  }
  sort(runner.begin(), runner.end());
  vector<info> v;
  for (int i = 0; i < (n); i++) {
    if (i == 0 || runner[i - 1].s != runner[i].s) v.push_back(runner[i]);
  }
  runner = v;
  n = v.size();
  for (int i = 0; i < (n); i++) swap(runner[i].s, runner[i].r);
  sort(runner.begin(), runner.end());
  v.clear();
  for (int i = 0; i < (n); i++) {
    if (i == 0 || runner[i - 1].s != runner[i].s) v.push_back(runner[i]);
  }
  for (int i = 0; i < (n); i++) swap(runner[i].s, runner[i].r);
  sort(runner.begin(), runner.end());
  vector<info> st;
  for (int i = 0; i < (v.size()); i++) {
    info cur = v[i];
    int k = st.size();
    while (k >= 2 && !isConvex(st[k - 2].r, st[k - 2].s, st[k - 1].r,
                               st[k - 1].s, cur.r, cur.s)) {
      st.pop_back();
      k = st.size();
    }
    while (k >= 1 && !isPositive(st[k - 1].r, st[k - 1].s, cur.r, cur.s)) {
      st.pop_back();
      k = st.size();
    }
    st.push_back(cur);
  }
  vector<int> res;
  for (int i = 0; i < (st.size()); i++) {
    vector<int>& cv = id[make_pair(st[i].r, st[i].s)];
    for (vector<int>::iterator it = cv.begin(); it != cv.end(); it++)
      res.push_back(*it);
  }
  sort(res.begin(), res.end());
  for (int i = 0; i < (res.size()); i++) printf("%d ", res[i]);
  puts("");
  return 0;
}
