#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
  point operator-(const point& other) const {
    return point(other.x - x, other.y - y);
  }
  long long operator/(const point& other) const {
    return x * 1LL * other.y - y * 1LL * other.x;
  }
  bool operator<(const point& other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
  bool operator==(const point& other) const {
    return x == other.x && y == other.y;
  }
  bool operator!=(const point& other) const { return !(*this == other); }
};
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
const int maxn = 4e5 + 5;
int n, c, d;
map<point, int> mp;
vector<point> p;
long long pref[maxn];
void read_input() {
  cin >> n >> c >> d;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    x -= c;
    y -= d;
    int t = gcd(abs(x), abs(y));
    x /= t;
    y /= t;
    if (mp.count(point(x, y)) == 0) p.push_back(point(x, y));
    ++mp[point(x, y)];
  }
}
int up(point u) {
  if (u.y == 0) return u.x > 0;
  return u.y > 0;
}
bool cmp(const point& u, const point& v) {
  int up_u = up(u), up_v = up(v);
  if (up_u == up_v) return u / v > 0;
  return up_u > up_v;
}
void init() {
  sort(p.begin(), p.end(), cmp);
  pref[0] = 0;
  for (int i = 0; i < (int)p.size(); ++i) pref[i + 1] = pref[i] + mp[p[i]];
}
point modify(point u) { return point(-u.x, -u.y); }
void solve() {
  long long ans = 0;
  long long total_cnt = 0;
  long long total = 0;
  for (int cur = 0, nxt = 0; cur < (int)p.size(); ++cur) {
    int t = upper_bound(p.begin(), p.end(), modify(p[cur]), cmp) - p.begin();
    if (up(p[cur])) t = 0;
    total -= mp[p[cur]] * 1LL * pref[t];
    total_cnt -= mp[p[cur]];
    while (nxt < (int)p.size() && p[cur] / p[nxt] >= 0 &&
           modify(p[cur]) != p[nxt]) {
      t = upper_bound(p.begin(), p.end(), modify(p[nxt]), cmp) - p.begin();
      if (up(p[nxt])) t = 0;
      total += mp[p[nxt]] * 1LL * pref[t];
      total_cnt += mp[p[nxt]];
      ++nxt;
    }
    t = upper_bound(p.begin(), p.end(), modify(p[cur]), cmp) - p.begin();
    if (up(p[cur])) t = 0;
    ans += mp[p[cur]] * 1LL * total;
    ans -= mp[p[cur]] * 1LL * pref[t] * total_cnt;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  read_input();
  init();
  solve();
}
