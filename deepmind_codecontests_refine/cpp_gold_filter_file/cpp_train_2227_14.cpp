#include <bits/stdc++.h>
using namespace std;
struct P {
  long long x, y;
  void read() {
    int xx, yy;
    scanf("%d%d", &xx, &yy);
    x = (xx + yy);
    y = (xx - yy);
  }
} p[100010];
inline bool operator<(const P &a, const P &b) { return a.x < b.x; }
long long sl[100010], bl[100010], sr[100010], br[100010];
int n;
bool chk(long long m) {
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && p[j].x - p[i].x <= m) j++;
    if (i == 0 && j == n) {
      return 1;
    } else if (i == 0) {
      if (br[j] - sr[j] <= m) return 1;
    } else if (j == n) {
      if (bl[i - 1] - sl[i - 1] <= m) return 1;
    } else {
      if (max(bl[i - 1], br[j]) - min(sl[i - 1], sr[j]) <= m) return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) p[i].read();
  sort(p, p + n);
  sl[0] = bl[0] = p[0].y;
  for (int i = 1; i < n; i++) {
    sl[i] = min(sl[i - 1], p[i].y);
    bl[i] = max(bl[i - 1], p[i].y);
  }
  sr[n - 1] = br[n - 1] = p[n - 1].y;
  for (int i = n - 2; i >= 0; i--) {
    sr[i] = min(sr[i + 1], p[i].y);
    br[i] = max(br[i + 1], p[i].y);
  }
  long long l = 0, r = 2e9;
  while (l != r) {
    long long m = (l + r) / 2;
    if (chk(m))
      r = m;
    else
      l = m + 1;
  }
  printf("%.14f\n", 0.5 * l);
  return 0;
}
