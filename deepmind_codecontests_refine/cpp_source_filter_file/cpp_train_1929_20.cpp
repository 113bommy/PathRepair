#include <bits/stdc++.h>
const int INF = 1 << 30;
const long long LINF = 1ll << 62;
const unsigned long long ULINF = 1ull << 63;
using namespace std;
struct vec {
  long double x, y;
  long double len2() { return x * x + y * y; }
  long double len() { return sqrtl(len2()); }
  void norma() {
    long double leng = len();
    x /= leng;
    y /= leng;
  }
};
vec operator+(vec a, vec b) { return {a.x + b.x, a.y + b.y}; }
vec operator-(vec a, vec b) { return {a.x - b.x, a.y - b.y}; }
vec operator*(vec a, long double b) { return {a.x * b, a.y * b}; }
vec operator*(long double b, vec a) { return {a.x * b, a.y * b}; }
long double vecpr(vec v1, vec v2) { return v1.x * v2.y - v1.y * v2.x; }
long double scalpr(vec v1, vec v2) { return v1.x * v2.x + v1.y * v2.y; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vec p, dir;
  long double a, b, c, d;
  cin >> p.x >> p.y >> dir.x >> dir.y >> a >> b >> c >> d;
  dir.norma();
  vector<vec> ans;
  ans.push_back({p.x + dir.x * b, p.y + dir.y * b});
  dir = {-dir.y, dir.x};
  ans.push_back({p.x + dir.x * (a / 2), p.y + dir.y * (a / 2)});
  ans.push_back({p.x + dir.x * (c / 2), p.y + dir.y * (c / 2)});
  dir = {dir.y, dir.x};
  ans.push_back({ans[2].x + dir.x * d, ans[2].y + dir.y * d});
  dir = {-dir.y, dir.x};
  ans.push_back({ans[3].x + dir.x * c, ans[3].y + dir.y * c});
  ans.push_back({p.x + dir.x * (c / 2), p.y + dir.y * (c / 2)});
  ans.push_back({p.x + dir.x * (a / 2), p.y + dir.y * (a / 2)});
  cout << fixed << setprecision(10);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].x << " " << ans[i].y << endl;
  }
}
