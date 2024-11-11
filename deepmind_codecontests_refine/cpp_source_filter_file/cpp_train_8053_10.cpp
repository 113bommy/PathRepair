#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int num = 0, k = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') k = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    num *= 10, num += ch - 48, ch = getchar();
  }
  return num * k;
}
struct point {
  long long x, y;
  bool operator<(const point &b) const { return x != b.x ? x < b.x : y > b.y; }
} p[100000 + 5];
int a, b, c, d, ans = 0, f[100000 + 5], cnt = 0, n;
long long q[100000 + 5];
int getAns(int x) {
  int l = 1, r = cnt;
  if (q[cnt] < x) {
    q[++cnt] = x;
    return cnt;
  }
  while (l < r) {
    int mid = l + r >> 1;
    if (q[mid] < x)
      l = mid + 1;
    else
      r = mid;
  }
  q[l] = x;
  return l;
}
int main() {
  scanf("%d", &n);
  a = read(), b = read(), c = read(), d = read();
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i].x = c * 1ll * x - d * 1ll * y;
    p[i].y = b * 1ll * y - a * 1ll * x;
  }
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n; i++)
    if (p[i].y > 0 && p[i].x > 0) f[i] = getAns(p[i].y), ans = max(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
