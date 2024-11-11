#include <bits/stdc++.h>
using namespace std;
struct data {
  int id, h, w;
} A[200009], B[200009];
int a[200009], f[200009], g[200009], s[200009], ans = 0;
inline bool cmp(data aa, data bb) { return aa.h > bb.h; }
inline bool cmp1(data aa, data bb) { return aa.id < bb.id; }
void solve(int l, int r) {
  if (r - l < 2) return;
  int mid = (l + r) >> 1;
  solve(l, mid), solve(mid, r);
  sort(A + l, A + mid, cmp), sort(B + mid + 1, B + r, cmp);
  for (int i = l, j = mid, zd = 0; i < mid; i++) {
    while (j < r && B[j + 1].h + 1 >= A[i].h) j++, zd = max(zd, B[j].w);
    ans = max(ans, A[i].w + zd);
  }
  sort(A + l, A + mid, cmp1), sort(B + mid + 1, B + r, cmp1);
}
int main() {
  int n, tp = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i] -= i;
  s[tp] = -1e9;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= s[tp])
      s[++tp] = a[i], f[i] = tp;
    else {
      int p = upper_bound(s + 1, s + tp + 1, a[i]) - s;
      f[i] = p, s[p] = a[i];
    }
  }
  memset(s, 0, sizeof(s));
  s[tp = 0] = 1e9;
  for (int i = n; i > 0; i--) {
    if (a[i] <= s[tp])
      s[++tp] = a[i], g[i] = tp;
    else {
      int p = upper_bound(s + 1, s + tp + 1, a[i], greater<int>()) - s;
      g[i] = p, s[p] = a[i];
    }
  }
  for (int i = 1; i <= n; i++)
    A[i] = (data){i, a[i], f[i]}, B[i] = (data){i, a[i], g[i]},
    ans = max(ans, f[i]);
  solve(1, n), printf("%d", n - 1 - ans);
  return 0;
}
