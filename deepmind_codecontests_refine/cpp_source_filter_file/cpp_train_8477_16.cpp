#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MAGIC = 400;
int n, lima, limb, w;
long long coef[maxn];
struct point {
  long long a, b;
  point(){};
  point(long long a, long long b) : a(a), b(b){};
  point operator-(point other) { return point(a - other.a, b - other.b); }
  long long operator*(point other) { return a * other.b - b * other.a; };
};
struct CHT {
  int L, R, it, m, x = 0;
  vector<point> hull;
  void add(int pos) {
    for (int i = L; i <= pos; ++i) coef[i] += i;
    build();
  }
  void build() {
    hull.clear();
    m = it = 0;
    for (int i = L; i <= R; ++i) {
      while (m >= 2 &&
             (hull[m - 2] - hull[m - 1]) * (point(i, coef[i]) - hull[m - 1]) <=
                 0)
        --m, hull.pop_back();
      ++m;
      hull.push_back(point(i, coef[i]));
    }
  }
  pair<long long, long long> ask() {
    while (it + 1 < hull.size() &&
           x * hull[it].a + hull[it].b <= x * hull[it + 1].a + hull[it + 1].b)
      ++it;
    return make_pair(x * hull[it].a + hull[it].b, hull[it].a);
  }
} b[MAGIC];
pair<int, int> a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("A"
            ".INP",
            "r")) {
    freopen(
        "A"
        ".INP",
        "r", stdin);
    freopen(
        "A"
        ".OUT",
        "w", stdout);
  }
  cin >> n >> w;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].second >> a[i].first;
    limb = max(limb, a[i].first + 1);
    lima = max(lima, a[i].second);
  }
  for (int i = 0; i <= lima; i += MAGIC) {
    b[i / MAGIC].L = i;
    b[i / MAGIC].R = min(lima, i + MAGIC - 1);
    b[i / MAGIC].build();
  }
  sort(a + 1, a + n + 1);
  int it = 1;
  for (int i = 0; i <= limb; ++i) {
    auto add = [&](int x) {
      for (int i = 0; i <= x; i += MAGIC) {
        if (i + MAGIC > x) {
          b[i / MAGIC].add(x);
          break;
        }
        b[i / MAGIC].x++;
      }
    };
    while (it <= n && a[it].first < i) add(a[it++].second);
    pair<long long, long long> res = make_pair(-1, 0);
    for (int j = 1; j <= lima; j += MAGIC) {
      res = max(res, b[j / MAGIC].ask());
    }
    cout << res.first + 1ll * w * i * (n - it + 1) << " " << res.second << '\n';
  }
}
