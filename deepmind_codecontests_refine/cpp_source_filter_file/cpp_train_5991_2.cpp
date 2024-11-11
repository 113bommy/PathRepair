#include <bits/stdc++.h>
using namespace std;
const double g = 10.0, eps = 1e-12;
const int N = 300000 + 10, maxn = 400000 + 10;
struct point {
  long long x, y;
  point(long long x = 0, long long y = 0) : x(x), y(y) {}
  bool operator<(const point &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
  point operator+(const point &rhs) const {
    return point(x + rhs.x, y + rhs.y);
  }
  point operator-(const point &rhs) const {
    return point(x - rhs.x, y - rhs.y);
  }
  long long operator*(const point &rhs) const { return x * rhs.y - y * rhs.x; }
} p[N];
int en[N];
long long ask[N], ans;
vector<point> pointset[N << 2];
void update(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    pointset[rt].push_back(p[L]);
    return;
  }
  int m = (l + r) >> 1;
  if (L <= m) update(L, R, l, m, rt << 1);
  if (m < R) update(L, R, m + 1, r, rt << 1 | 1);
}
void dfs(int l, int r, int rt) {
  vector<point> &v = pointset[rt];
  if (!v.size()) sort(v.begin(), v.end());
  if (v.size() > 2) {
    int i, j;
    for (i = 2, j = 1; i < v.size(); i++) {
      while (j > 0 && (v[j] - v[j - 1]) * (v[i] - v[j]) >= 0) j--;
      j++;
      v[j] = v[i];
    }
    while (v.size() > j + 1) v.pop_back();
  }
  if (l == r) return;
  int m = (l + r) >> 1;
  dfs(l, m, rt << 1);
  dfs(m + 1, r, rt << 1 | 1);
}
long long fun(point p, long long v) { return p.x * v + p.y; }
long long solve(vector<point> &v, long long c) {
  long long ans = -9223372036854775807ll;
  int l = 0, r = v.size() - 1;
  while (r - l > 6) {
    int m1 = (l * 2 + r) / 3;
    int m2 = (l + r * 2) / 3;
    if (fun(v[m1], c) < fun(v[m2], c))
      l = m1;
    else
      r = m2;
  }
  for (int i = l; i <= r; i++) ans = max(ans, fun(v[i], c));
  return ans;
}
void query(int pos, long long c, int l, int r, int rt) {
  ans = max(ans, solve(pointset[rt], c));
  if (l == r) return;
  int m = (l + r) >> 1;
  if (pos <= m)
    query(pos, c, l, m, rt << 1);
  else
    query(pos, c, m + 1, r, rt << 1 | 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    en[i] = -1;
    ask[i] = -9223372036854775807ll;
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%lld%lld", &p[i].x, &p[i].y);
      en[i] = n;
    } else if (t == 2) {
      int x;
      scanf("%d", &x);
      en[x] = i - 1;
    } else {
      scanf("%lld", &ask[i]);
    }
  }
  for (int i = 1; i <= n; i++)
    if (en[i] != -1) update(i, en[i], 1, n, 1);
  dfs(1, n, 1);
  for (int i = 1; i <= n; i++) {
    if (ask[i] != -9223372036854775807ll) {
      ans = -9223372036854775807ll;
      query(i, ask[i], 1, n, 1);
      if (ans == -9223372036854775807ll)
        puts("EMPTY SET");
      else
        printf("%lld\n", ans);
    }
  }
  return 0;
}
