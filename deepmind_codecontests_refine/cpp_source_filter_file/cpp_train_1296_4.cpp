#include <bits/stdc++.h>
using namespace std;
const int N = 201010;
int n, i, ans[N];
struct g {
  int l, r, id;
} a[N];
bool cmp(g a, g b) {
  if (a.l == b.l) return a.r > b.r;
  return a.l < b.l;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].l, &a[i].r);
    a[i].id = i;
  }
  while (1) {
    sort(a + 1, a + 1 + n, cmp);
    for (i = 1; i < n; i++)
      if (a[i].l == a[i + 1].l) break;
    if (i == n) break;
    a[i].l++;
  }
  for (i = 1; i <= n; i++) ans[a[i].id] = a[i].l;
  for (i = 1; i <= n; i++) printf("%d ", a[i].l);
}
