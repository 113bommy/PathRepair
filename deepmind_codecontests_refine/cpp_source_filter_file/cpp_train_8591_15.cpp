#include <bits/stdc++.h>
const long long MAXN = 15;
struct Node {
  long long x, y;
  Node(long long x = 0, long long y = 0) : x(x), y(y) {}
} a[5], ans[5], c[5], _[MAXN];
long long res;
long long opt[MAXN], b[MAXN];
std::vector<long long> rx, ry;
inline bool cmp1(long long x, long long y) { return a[x].x < a[y].x; }
inline bool cmp2(long long x, long long y) { return a[x].y < a[y].y; }
long long p[MAXN];
inline void upmax(long long gx) {
  if (gx < res) {
    res = gx;
    for (long long i = 1; i <= 4; ++i) ans[i] = _[i];
  }
}
inline void upall() {
  for (long long i = 1; i <= 4; ++i) p[i] = i;
  do {
    long long gx = 0;
    bool flag = 1;
    for (long long i = 1; i <= 4; ++i) {
      long long dx = std::abs(c[p[i]].x - a[i].x),
                dy = std::abs(c[p[i]].y - a[i].y);
      if (dx && dy) {
        flag = 0;
        break;
      }
      _[i] = c[p[i]];
      gx = std::max(gx, dx + dy);
    }
    if (!flag) continue;
    upmax(gx);
  } while (std::next_permutation(p + 1, p + 4 + 1));
}
inline void chk() {
  std::sort(rx.begin(), rx.end());
  std::sort(ry.begin(), ry.end());
  rx.erase(std::unique(rx.begin(), rx.end()), rx.end());
  ry.erase(std::unique(ry.begin(), ry.end()), ry.end());
  if (rx.size() == 2 || ry.size() == 2) {
    if (rx.size() == 2 && ry.size() == 2) {
      if (rx[0] != rx[1] && ry[0] != ry[1]) {
        if (rx[1] - rx[0] != ry[1] - ry[0]) return;
        for (long long i = 0; i <= 1; ++i)
          for (long long j = 0; j <= 1; ++j)
            c[i * 2 + j + 1] = Node(rx[i], ry[j]);
        upall();
        return;
      }
    }
    if (rx.size() == 2 && ry.size() == 1) {
      long long D = rx[1] - rx[0];
      for (long long i = 0; i <= 1; ++i) c[i + 1] = Node(rx[i], ry[0]);
      for (long long i = 3; i <= 4; ++i) c[i] = c[i - 2], c[i].y += D;
      upall();
      for (long long i = 2; i <= 3; ++i) c[i] = c[i - 2], c[i].y -= D;
      upall();
      return;
    }
    if (ry.size() == 2 && rx.size() == 1) {
      long long D = ry[1] - ry[0];
      for (long long i = 0; i <= 1; ++i) c[i + 1] = Node(rx[0], ry[i]);
      for (long long i = 3; i <= 4; ++i) c[i] = c[i - 2], c[i].x += D;
      upall();
      for (long long i = 2; i <= 3; ++i) c[i] = c[i - 2], c[i].x -= D;
      upall();
      return;
    }
  }
  if (rx.empty() && ry.size() == 2) {
    long long y1 = ry[0], y2 = ry[1];
    long long D = y2 - y1;
    std::vector<long long> v1, v2;
    for (long long i = 1; i <= 4; ++i) {
      if (a[i].y == y1)
        v1.push_back(i);
      else
        v2.push_back(i);
    }
    for (long long _ = 0; _ <= 1; ++_) {
      for (long long i = 0; i <= 1; ++i) {
        for (long long j = 0; j <= 1; ++j) {
          long long mn = std::min(
              {a[v1[0]].x, a[v1[1]].x - D, a[v2[0]].x, a[v2[1]].x - D});
          long long mx = std::max(
              {a[v1[0]].x, a[v1[1]].x - D, a[v2[0]].x, a[v2[1]].x - D});
          long long tt = (mn + mx) / 2;
          for (long long x = tt - 1; x <= tt + 1; ++x) {
            c[1] = Node(x, y1);
            c[2] = Node(x + D, y1);
            c[3] = Node(x, y2);
            c[4] = Node(x + D, y2);
            upall();
          }
          std::swap(v2[0], v2[1]);
        }
        std::swap(v1[0], v1[1]);
      }
      D = -D;
    }
  }
  if (ry.empty() && rx.size() == 2) {
    long long x1 = rx[0], x2 = rx[1];
    long long D = x2 - x1;
    std::vector<long long> v1, v2;
    for (long long i = 1; i <= 4; ++i) {
      if (a[i].x == x1)
        v1.push_back(i);
      else
        v2.push_back(i);
    }
    for (long long _ = 0; _ <= 1; ++_) {
      for (long long i = 0; i <= 1; ++i) {
        for (long long j = 0; j <= 1; ++j) {
          long long mn = std::min(
              {a[v1[0]].y, a[v1[1]].y - D, a[v2[0]].y, a[v2[1]].y - D});
          long long mx = std::max(
              {a[v1[0]].y, a[v1[1]].y - D, a[v2[0]].y, a[v2[1]].y - D});
          long long tt = (mn + mx) / 2;
          for (long long y = tt - 1; y <= tt + 1; ++y) {
            c[1] = Node(x1, y);
            c[2] = Node(x1, y + D);
            c[3] = Node(x2, y);
            c[4] = Node(x2, y + D);
            upall();
          }
          std::swap(v2[0], v2[1]);
        }
        std::swap(v1[0], v1[1]);
      }
      D = -D;
    }
  }
}
inline void Solve() {
  for (long long i = 1; i <= 4; ++i) scanf("%lld%lld", &a[i].x, &a[i].y);
  res = 1e18;
  for (long long S = 0; S <= (1 << 4) - 1; ++S) {
    rx.clear();
    ry.clear();
    for (long long i = 0; i <= 3; ++i) {
      if ((S >> i) & 1)
        rx.push_back(a[i + 1].x);
      else
        ry.push_back(a[i + 1].y);
    }
    chk();
  }
  if (res == 1e18) {
    puts("-1");
    return;
  }
  printf("%lld\n", res);
  for (long long i = 1; i <= 4; ++i) printf("%lld %lld\n", ans[i].x, ans[i].y);
}
signed main() {
  long long T;
  scanf("%lld", &T);
  while (T--) Solve();
  return 0;
}
