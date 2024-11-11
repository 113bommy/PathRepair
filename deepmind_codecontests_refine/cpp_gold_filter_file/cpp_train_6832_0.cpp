#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
struct pt {
  pt(long long x, long long y) : x(x), y(y){};
  long long x, y;
};
bool cmp(pt a, pt b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
bool cw(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}
bool ccw(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
void convex_hull(vector<pt>& a) {
  if (a.size() == 1) return;
  sort(a.begin(), a.end(), &cmp);
  pt p1 = a[0], p2 = a.back();
  vector<pt> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (size_t i = 1; i < a.size(); ++i) {
    if (i == a.size() - 1 || cw(p1, a[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
        up.pop_back();
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
      while (down.size() >= 2 &&
             !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
        down.pop_back();
      down.push_back(a[i]);
    }
  }
  a.clear();
  for (size_t i = 0; i < up.size(); ++i) a.push_back(up[i]);
  for (size_t i = down.size() - 2; i > 0; --i) a.push_back(down[i]);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(b, a % b);
  return gcd(a, b % a);
}
int main() {
  int n;
  scanf("%d", &n);
  std::vector<long long> x(n);
  std::vector<long long> y(n);
  for (int i = 0; i < n; i++) scanf("%lld %lld", &x[i], &y[i]);
  long long mx = 0, my = 0;
  for (int i = 0; i < n; i++) mx += 2 * x[i], my += 2 * y[i];
  for (int i = 0; i < n; i++) x[i] *= n * 2, y[i] *= n * 2;
  std::vector<int> dead(n, 0);
  for (int i = 0; i < n; i++)
    if (x[i] == mx && y[i] == my) {
      dead[i] = 1;
    }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (!dead[i] && !dead[j] && x[i] - mx == mx - x[j] &&
          y[i] - my == my - y[j]) {
        dead[i] = 1;
        dead[j] = 1;
      }
    }
  std::vector<long long> nx, ny;
  for (int i = 0; i < n; i++)
    if (!dead[i]) nx.push_back(x[i]), ny.push_back(y[i]);
  x = nx;
  y = ny;
  n = x.size();
  if (n <= 2) {
    printf("-1");
    return 0;
  }
  vector<pt> poly;
  for (int i = 0; i < n; i++) poly.push_back(pt(x[i], y[i]));
  convex_hull(poly);
  if (poly.size() == 1) {
    printf("-1");
    return 0;
  } else if (poly.size() == 2) {
    bool can = true;
    sort((x).begin(), (x).end());
    for (int i = 0; i < n; i++)
      if (mx - x[i] != x[n - 1 - i] - mx) can = false;
    if (can)
      printf("-1");
    else
      printf("1");
    return 0;
  }
  int k = poly.size();
  std::vector<std::pair<int, int> > q;
  for (int i = 0; i < k; i++) {
    pt a = poly[i];
    pt b = poly[(i + 1) % k];
    for (int j = i + 1; j < i + n - 1; j++) {
      pt c = poly[j % k];
      pt d = poly[(j + 1) % k];
      pt e = poly[(j + 2) % k];
      pt bcd(b.x + d.x - c.x, b.y + d.y - c.y);
      pt aed(a.x + d.x - e.x, a.y + d.y - e.y);
      if (!cw(bcd, b, a) && !cw(aed, b, a)) {
        q.push_back(make_pair((j + 1) % k, i % k));
        q.push_back(make_pair((j + 1) % k, (i + 1) % k));
      }
    }
  }
  std::vector<std::pair<long long, long long> > ans;
  for (auto pix : q) {
    pt a = poly[pix.first];
    pt b = poly[pix.second];
    long long px = (a.x + b.x) / 2;
    long long py = (a.y + b.y) / 2;
    px -= mx;
    py -= my;
    long long d = gcd(abs(px), abs(py));
    px /= d;
    py /= d;
    std::vector<long long> dist;
    for (int i = 0; i < n; i++) {
      long long tx = x[i] - mx;
      long long ty = y[i] - my;
      dist.push_back(-tx / 2 * py + ty / 2 * px);
    }
    sort((dist).begin(), (dist).end());
    bool can = true;
    for (int i = 0; i < n; i++)
      if (dist[i] + dist[n - 1 - i] != 0) can = false;
    if (can) {
      long long d = gcd(abs(px), abs(py));
      px /= d;
      py /= d;
      if (py < 0) {
        px = -px;
        py = -py;
      } else if (py == 0 && px < 0) {
        px = -px;
        py = -py;
      }
      ans.push_back(make_pair(px, py));
    }
  }
  sort((ans).begin(), (ans).end());
  int res = 0;
  for (int i = 0; i < ans.size(); i++)
    if (i == 0 || ans[i] != ans[i - 1]) res++;
  cout << res;
}
