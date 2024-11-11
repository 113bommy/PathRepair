#include <bits/stdc++.h>
void err() { std::cout << std::endl; }
template <typename T, typename... Args>
void err(T a, Args... args) {
  std::cout << a << ' ';
  err(args...);
}
using namespace std;
const int mod = 998244353;
const int inf = 1e9 + 7;
const int maxn = 300000 + 5;
int dis(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int n, ls[maxn], rs[maxn];
int ans[maxn], d[maxn];
pair<int, int> a[maxn], p[4];
set<pair<int, int> > hp;
int main() {
  scanf("%d", &n);
  pair<int, int> t = {-inf, -inf}, d = {inf, inf}, l = {inf, inf},
                 r = {-inf, -inf};
  int maxx, minx, maxy, miny;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
    if (a[i].first < l.first) l = a[i], minx = a[i].first;
    if (a[i].first > r.first) r = a[i], maxx = a[i].first;
    if (a[i].second > t.second) t = a[i], maxy = a[i].second;
    if (a[i].second < d.second) d = a[i], miny = a[i].second;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, maxx - a[i].first + maxy - a[i].second);
    ans = max(ans, maxx - a[i].first + a[i].second - maxy);
    ans = max(ans, a[i].first - minx + maxy - a[i].second);
    ans = max(ans, a[i].first - minx + a[i].second - maxy);
  }
  printf("%d ", 2 * ans);
  for (int i = 4; i <= n; i++) printf("%d ", 2 * (maxx - minx + maxy - miny));
  return 0;
}
