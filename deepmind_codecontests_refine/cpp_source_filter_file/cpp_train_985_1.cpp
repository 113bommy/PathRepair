#include <bits/stdc++.h>
using namespace std;
int m;
char s[2000100];
int a[2000100], pre[2000100], suf[2000100];
int sa[2000100], rnk[2000100], lcp[2000100], cnt[2000100];
void build(char *s) {
  int n = strlen(s) + 1, m = 256;
  int *x = rnk, *y = lcp, *z;
  for (int i = 0; i < m; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) cnt[x[i] = s[i]]++;
  for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
  for (int i = n - 1; i >= 0; i--) sa[--cnt[x[i]]] = i;
  for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
    p = 0;
    for (int i = n - j; i < n; i++) y[p++] = i;
    for (int i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (int i = 0; i < m; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) cnt[x[i]]++;
    for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--cnt[x[y[i]]]] = y[i];
    z = x, x = y, y = z;
    x[sa[0]] = 0, p = 1;
    for (int i = 1; i < n; i++) {
      x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + j] == y[sa[i - 1] + j])
                     ? p - 1
                     : p++;
    }
  }
}
int main() {
  scanf("%s", s + 1);
  m = strlen(s + 1);
  for (int i = 1; i <= m; i++) a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
  pre[0] = 2000100;
  for (int i = 1; i <= m; i++) pre[i] = min(pre[i - 1], a[i]);
  suf[m + 1] = 2000100;
  for (int i = m - 1; i >= 0; i--) suf[i] = min(suf[i + 1], a[i]);
  for (int i = 1; i <= m; i++) s[m + i] = s[i];
  build(s + 1);
  for (int i = 0; i <= 2 * m; i++)
    if (sa[i] < m) {
      int j = sa[i] + 1;
      bool ok = 0;
      if (a[m] >= 0) {
        if (min(suf[j], a[m] + pre[j - 1]) >= a[j - 1]) {
          ok = 1;
        }
      } else {
        if (min(-a[m] + suf[j], pre[j - 1]) >= a[j - 1]) {
          ok = 1;
        }
      }
      if (ok) {
        rotate(s + 1, s + j, s + m + 1);
        s[m + 1] = 0;
        if (a[m] >= 0) {
          printf("%s", s + 1);
          while (a[m]--) putchar(')');
        } else {
          a[m] = -a[m];
          while (a[m]--) putchar('(');
          printf("%s", s + 1);
        }
        return 0;
      }
    }
  return 0;
}
