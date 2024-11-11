#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a[N], t, n, m, k;
struct node {
  int l;
  int r;
  int w;
  bool operator<(const node &a) const {
    if (l != a.l) return l < a.l;
    return r < a.r;
  }
} b[N], c[N];
bool check(int mid) {
  int minn = a[mid];
  int i = 1, r = 0, l = 0;
  int cnt = 0;
  for (int j = 1; j <= k; j++) {
    if (b[j].w > minn) c[++cnt] = b[j];
  }
  int res = 0;
  while (i <= cnt) {
    int pr = c[i].r, pi = i;
    i++;
    while (i <= cnt && c[i].l <= pr) {
      if (c[i].w > minn) pr = max(c[i].r, pr);
      i++;
    }
    i--;
    res += (pr - c[pi].l) * 2;
    r = c[i].r;
    i++;
  }
  res += n + 1;
  return res <= t;
}
int main() {
  scanf("%d%d%d%d", &m, &n, &k, &t);
  for (int i = 1; i <= m; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + m);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].w);
  }
  sort(b + 1, b + 1 + k);
  a[0] = 0;
  a[m + 1] = 1e9 + 50;
  int l = 1, r = m, res = m + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, res = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", m - res + 1);
}
