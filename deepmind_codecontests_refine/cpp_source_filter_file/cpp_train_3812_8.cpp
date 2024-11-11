#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
struct point {
  int a, b, c, d, e;
} p[maxn];
int n;
vector<int> ans;
double mul(point x, point y) {
  return x.a * y.a + x.b * y.b + x.c * y.c + x.d * y.d + x.e * y.e;
}
double abs(point x) { return sqrt(mul(x, x)); }
bool bad(point a, point b, point c) {
  point x = {b.a - a.a, b.b - a.b, b.c - a.c, b.d - a.d, b.e - a.e};
  point y = {c.a - a.a, c.b - a.b, c.c - a.c, c.d - a.d, c.e - a.e};
  return acos(mul(x, y) / abs(x) / abs(y)) * 180.0 / acos(-1) < 90;
}
int main() {
  cin >> n;
  if (n > 10)
    puts("0");
  else {
    for (int i = 1; i <= n; ++i)
      cin >> p[i].a >> p[i].b >> p[i].c >> p[i].d >> p[i].e;
    for (int i = 1; i <= n; ++i) {
      bool ok = 1;
      for (int j = 1; j <= n; ++j)
        for (int k = j; k <= n; ++k)
          if (i != j && j != k && i != k && bad(p[i], p[j], p[k])) ok = 0;
      if (ok) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto v : ans) cout << v << '\n';
  }
  return 0;
}
