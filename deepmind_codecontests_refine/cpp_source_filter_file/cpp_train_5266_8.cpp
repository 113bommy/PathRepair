#include <bits/stdc++.h>
using namespace std;
const int mxn = 1000100;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 - '0' + ch;
    ch = getchar();
  }
  return x * f;
}
struct node {
  int w, id;
} a[mxn], b[mxn];
int cmp(const node a, const node b) { return a.w < b.w; }
int n, m, k;
bool check(int lim) {
  int i, j;
  int day = 0, now = 0;
  for (i = 1, j = m - lim + 1; i <= n || j <= m;) {
    if (i <= n && (j > m || a[i].w <= b[j].w)) {
      now++;
      if (now > k) {
        now -= k;
        day++;
      }
      if (a[i].w < day) return 0;
      i++;
    } else {
      now++;
      if (now > k) {
        now -= k;
        day++;
      }
      if (b[i].w < day) return 0;
      j++;
    }
  }
  return 1;
}
int main() {
  int i, j;
  n = read();
  m = read();
  k = read();
  for (i = 1; i <= n; i++) {
    a[i].w = read();
  }
  for (i = 1; i <= m; i++) {
    b[i].w = read();
    b[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  sort(b + 1, b + m + 1, cmp);
  int l = 0, r = m, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  if (!ans)
    if (!check(0)) ans = -1;
  printf("%d\n", ans);
  for (i = m - ans + 1; i <= m; i++) {
    printf("%d ", b[i].id);
  }
  return 0;
}
