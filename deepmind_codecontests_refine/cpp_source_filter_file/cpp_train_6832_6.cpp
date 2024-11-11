#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int T, n, ans, vn;
struct NODE {
  int x, y;
  bool operator==(const NODE &u) const { return (x == u.x && y == u.y); }
  bool operator<(const NODE &v) const {
    if (x != v.x) return x < v.x;
    return y < v.y;
  }
  void clear() { x = y = 0; }
  void print() { cout << x << " " << y << endl; }
} nd[N], ctr, vec[N * N];
bool out[N];
bool check(NODE u, NODE v) {
  return (1ll * u.x - ctr.x == 1ll * ctr.x - v.x &&
          1ll * u.y - ctr.y == 1ll * ctr.y - v.y);
}
int gcd(int x, int y) {
  int r;
  while (y) {
    r = x % y;
    x = y;
    y = r;
  }
  return x;
}
NODE GgG(NODE u) {
  int x = u.x;
  int y = u.y;
  if (x < 0)
    x *= -1, y *= -1;
  else if (x == 0 && y < 0)
    y *= -1;
  int d = gcd(x, y);
  x /= d;
  y /= d;
  return (NODE){x, y};
}
long long cross(NODE u, NODE v) { return 1ll * v.x * u.y - 1ll * u.x * v.y; }
bool check1(NODE u) {
  long long dis[N];
  for (int i = 1; i <= n; ++i) dis[i] = cross(nd[i], u);
  sort(dis + 1, dis + n + 1);
  for (int i = 1, sz = n / 2; i <= sz; ++i)
    if (dis[i] != -dis[n - i + 1]) return false;
  return true;
}
signed main() {
  scanf("%d", &n);
  ctr.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &nd[i].x, &nd[i].y);
    ctr.x += nd[i].x;
    ctr.y += nd[i].y;
    nd[i].x *= n;
    nd[i].y *= n;
  }
  memset(out, 0, sizeof(out));
  for (int i = 1; i <= n; ++i)
    if (!out[i]) {
      for (int j = i + 1; j <= n; ++j) {
        bool fl = 0;
        if (!out[j] && check(nd[i], nd[j])) {
          out[i] = out[j] = 1;
          fl = 1;
        }
        if (fl) break;
      }
    }
  int rem = 0;
  for (int i = 1; i <= n; ++i)
    if (!out[i]) {
      nd[++rem] = nd[i];
      nd[i].x -= ctr.x;
      nd[i].y -= ctr.y;
    }
  n = rem;
  if (n <= 2) {
    printf("-1\n");
    return 0;
  }
  vn = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      vec[++vn] = GgG((NODE){nd[i].x + nd[j].x, nd[i].y + nd[j].y});
  sort(vec + 1, vec + vn + 1);
  vec[++vn] = (NODE){-1, -1};
  ans = 0;
  int cnt = 1;
  for (int i = 2; i <= vn; ++i) {
    if (vec[i] == vec[i - 1])
      ++cnt;
    else {
      if (cnt >= n / 2 && check1(vec[i - 1])) ++ans;
      cnt = 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
