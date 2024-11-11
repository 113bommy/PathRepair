#include <bits/stdc++.h>
using namespace std;
const int N = 300000 + 100;
const int oo = 1e9;
int n, q;
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
struct line {
  int a, b, c;
  line() {}
  line(int x1, int y1, int x2, int y2) {
    a = y1 - y2;
    b = x2 - x1;
    c = x1 * y2 - x2 * y1;
    int g = gcd(gcd(a, b), c);
    a /= g, b /= g, c /= g;
    if (a < 0) a *= -1, b *= -1, b *= -1;
  }
  bool operator<(const line &rhs) const {
    if (rhs.a != a) return a < rhs.a;
    if (rhs.b != b) return b < rhs.b;
    return c < rhs.c;
  }
  bool operator==(const line &rhs) const {
    return rhs.a == a && rhs.c == c && rhs.b == b;
  }
};
map<line, vector<int> > sh;
struct mat {
  double m[202][202];
  mat() { memset(m, 0, sizeof m); }
  mat operator*(const mat &rhs) const {
    mat f;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          f.m[i][j] = f.m[i][j] + m[i][k] * rhs.m[k][j];
    return f;
  }
};
pair<int, int> pnts[210];
mat dp[12], A;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%d%d", &pnts[i].first, &pnts[i].second);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      line lx =
          line(pnts[i].first, pnts[i].second, pnts[j].first, pnts[j].second);
      sh[lx].push_back(i);
      sh[lx].push_back(j);
    }
  }
  for (auto j : sh) {
    sort(j.second.begin(), j.second.end());
    j.second.resize(unique(j.second.begin(), j.second.end()) -
                    j.second.begin());
    sh[j.first] = j.second;
  }
  for (int i = 0; i < n; ++i) {
    vector<line> fx;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      fx.push_back(
          line(pnts[i].first, pnts[i].second, pnts[j].first, pnts[j].second));
    }
    sort(fx.begin(), fx.end());
    fx.resize(unique(fx.begin(), fx.end()) - fx.begin());
    for (auto ln : fx) {
      int sz = sh[ln].size();
      for (auto pp : sh[ln]) {
        A.m[i][pp] += 1.0 / (fx.size()) * 1.0 / sz;
      }
    }
  }
  dp[0] = A;
  for (int i = 1; i <= 11; ++i) dp[i] = dp[i - 1] * dp[i - 1];
  cin >> q;
  while (q--) {
    int t, m;
    scanf("%d%d", &t, &m);
    t--, m--;
    mat f;
    for (int i = 0; i < n; ++i) f.m[i][0] = (i == t);
    for (int j = 10; j >= 0; --j)
      if ((m & (1 << j))) {
        mat res;
        for (int row = 0; row < n; row++)
          for (int k = 0; k < n; ++k)
            res.m[row][0] = res.m[row][0] + dp[j].m[row][k] * f.m[k][0];
        f = res;
      }
    double bst = 0;
    for (auto ln : sh) {
      double temp = 0.0;
      for (auto pnt : ln.second) {
        temp += f.m[pnt][0];
      }
      temp *= 1.0 / ln.second.size();
      bst = max(bst, temp);
    }
    printf("%.9lf\n", bst);
  }
  return 0;
}
