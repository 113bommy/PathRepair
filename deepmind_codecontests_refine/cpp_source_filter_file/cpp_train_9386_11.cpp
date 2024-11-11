#include <bits/stdc++.h>
using namespace std;
struct rect {
  int a, b, c, d;
  rect() { a = b = c = d = 0; }
} m[2002], tmp[2002];
int n, ans, d[2002], nu[2002];
bool comp(int _, int __) { return d[_] < d[__]; }
void work(int l, int r) {
  if (!ans) return;
  if (l == r) return;
  for (int i = l; i <= r; ++i)
    d[i - l + 1] = m[i].a, d[i - l + 1 + (r - l + 1)] = m[i].c;
  for (int i = 1; i <= 2 * (r - l + 1); ++i) nu[i] = i;
  sort(nu + 1, nu + 2 * (r - l + 1), comp);
  int cnt = 0, q = 0;
  int i = 1, oi = 1;
  while (i <= 2 * (r - l + 1)) {
    oi = i;
    while (i <= 2 * (r - l + 1) && d[nu[i]] == d[nu[oi]]) {
      if (nu[i] > r - l + 1) cnt--;
      i++;
    }
    if (cnt == 0 && q > 0 && q < r - l + 1) {
      int k = q;
      for (int j = oi; j <= 2 * (r - l + 1); ++j) {
        if (nu[j] <= r - l + 1) tmp[++q] = m[nu[j] + l - 1];
      }
      for (int j = l; j <= r; ++j) m[j] = tmp[j - l + 1];
      work(l, l + k - 1);
      work(l + k, r);
      return;
    }
    i = oi;
    while (i <= 2 * (r - l + 1) && d[nu[i]] == d[nu[oi]]) {
      if (nu[i] <= r - l + 1) cnt++, tmp[++q] = m[nu[i] + l - 1];
      i++;
    }
  }
  for (int i = l; i <= r; ++i)
    d[i - l + 1] = m[i].b, d[i - l + 1 + (r - l + 1)] = m[i].d;
  for (int i = 1; i <= 2 * (r - l + 1); ++i) nu[i] = i;
  sort(nu + 1, nu + 2 * (r - l + 1), comp);
  cnt = 0, q = 0;
  i = 1, oi = 1;
  while (i <= 2 * (r - l + 1)) {
    oi = i;
    while (i <= 2 * (r - l + 1) && d[nu[i]] == d[nu[oi]]) {
      if (nu[i] > r - l + 1) cnt--;
      i++;
    }
    if (cnt == 0 && q > 0 && q < r - l + 1) {
      int k = q;
      for (int j = oi; j <= 2 * (r - l + 1); ++j) {
        if (nu[j] <= r - l + 1) tmp[++q] = m[nu[j] + l - 1];
      }
      for (int j = l; j <= r; ++j) m[j] = tmp[j - l + 1];
      work(l, l + k - 1);
      work(l + k, r);
      return;
    }
    i = oi;
    while (i <= 2 * (r - l + 1) && d[nu[i]] == d[nu[oi]]) {
      if (nu[i] <= r - l + 1) cnt++, tmp[++q] = m[nu[i] + l - 1];
      i++;
    }
  }
  ans = 0;
  return;
}
int main() {
  scanf("%d\n", &n);
  int ai, bi, ci, di;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d\n", &ai, &bi, &ci, &di);
    m[i].a = ai, m[i].b = bi, m[i].c = ci, m[i].d = di;
  }
  ans = 1;
  work(1, n);
  if (!ans)
    printf("NO");
  else
    printf("YES");
  return 0;
}
