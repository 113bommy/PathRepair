#include <bits/stdc++.h>
using namespace std;
const long long N = 200002;
long long n, m, l, r, p, t, k, ans, sum, tot, cnt, a[N], num[N], n1, n2, n3, l1,
    l2, l3, b[N], w[N];
struct node {
  long long v, id;
} c[N], d[N], e[N];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
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
bool cmp(node x, node y) { return x.v < y.v; }
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) num[i] = read();
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] == 1) n1++, c[n1].v = num[i], c[n1].id = i;
    if (a[i] == 2) n2++, d[n2].v = num[i], d[n2].id = i;
    if (a[i] == 3) n3++, e[n3].v = num[i], e[n3].id = i;
  }
  for (long long i = 1; i <= n; i++) {
    long long x = read();
    if (x != a[i]) {
      if (x == 1) n1++, c[n1].v = num[i], c[n1].id = i;
      if (x == 2) n2++, d[n2].v = num[i], d[n2].id = i;
      if (x == 3) n3++, e[n3].v = num[i], e[n3].id = i;
    }
  }
  sort(c + 1, c + n1 + 1, cmp);
  sort(d + 1, d + n2 + 1, cmp);
  sort(e + 1, e + n3 + 1, cmp);
  m = read();
  l1 = l2 = l3 = 1;
  for (long long i = 1; i <= m; i++) {
    long long x1, x2, x3;
    long long x = read();
    if (x == 1) {
      while (l1 <= n1 && b[c[l1].id] == 1) l1++;
      x1 = c[l1].v;
      if (l1 > n1) x1 = -1;
      cout << x1 << " ", b[c[l1].id] = 1;
    }
    if (x == 2) {
      while (l2 <= n2 && b[d[l2].id] == 1) l2++;
      x2 = d[l2].v;
      if (l2 > n2) x2 = -1;
      cout << x2 << " ", b[d[l2].id] = 1;
    }
    if (x == 3) {
      while (l3 <= n3 && b[e[l3].id] == 1) l3++;
      x3 = e[l3].v;
      if (l3 > n3) x3 = -1;
      cout << x3 << " ", b[e[l3].id] = 1;
    }
  }
  return 0;
}
