#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
struct node {
  int xl, xr, yl, yr, z, id;
} a[100005];
int l[100005], r[100005];
bool cmp(node a, node b) { return a.z < b.z; }
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  int n, ans, j;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i].xl = read();
    a[i].xr = read();
    a[i].yl = read();
    a[i].yr = read();
    a[i].z = read();
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    r[i] = i + 1;
    l[i] = i - 1;
  }
  r[0] = 1;
  l[0] = n;
  r[n] = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    ans = 0;
    x = read();
    y = read();
    for (j = r[0]; j; j = r[j]) {
      if (a[j].xl <= x && x <= a[j].xr && a[j].yl <= y && y <= a[j].yr) {
        r[l[j]] = r[j];
        l[r[j]] = l[j];
        break;
      }
    }
    printf("%d\n", a[j].id);
  }
  return 0;
}
