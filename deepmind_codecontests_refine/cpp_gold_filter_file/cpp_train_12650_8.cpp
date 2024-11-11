#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 5;
int sa[maxn], ran[maxn], height[maxn], c[maxn], r[maxn], cost[maxn], rr[maxn],
    l[maxn], st[maxn], lf[maxn];
long long sum[maxn];
char s[maxn];
bool myequal(int *y, int a, int b, int k) {
  return y[a] == y[b] && y[a + k] == y[b + k];
}
void radixsort(int *x, int *y, int n, int m) {
  for (int i = 0; i < m; ++i) c[i] = 0;
  for (int i = 0; i < n; ++i) ++c[x[y[i]]];
  for (int i = 1; i < m; ++i) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
}
void da(int n, int m) {
  int *x = ran, *y = height;
  ++n;
  for (int i = 0; i < n; ++i) {
    x[i] = r[i];
    y[i] = i;
  }
  radixsort(x, y, n, m);
  for (int k = 1, p = 0; p < n; k <<= 1, m = p) {
    p = 0;
    for (int i = n - k; i < n; ++i) y[p++] = i;
    for (int i = 0; i < n; ++i)
      if (sa[i] >= k) y[p++] = sa[i] - k;
    radixsort(x, y, n, m);
    swap(x, y);
    p = 1, x[sa[0]] = 0;
    for (int i = 1; i < n; ++i)
      x[sa[i]] = myequal(y, sa[i - 1], sa[i], k) ? p - 1 : p++;
  }
  --n;
  for (int i = 0; i <= n; ++i) ran[sa[i]] = i;
  for (int i = 0, k = 0; i < n; ++i) {
    if (k) --k;
    int j = sa[ran[i] - 1];
    while (r[i + k] == r[j + k]) ++k;
    height[ran[i]] = k;
  }
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int len = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s);
      int m = strlen(s);
      for (int j = 0; s[j]; ++j) {
        r[len] = s[j] + n;
        l[len] = m--;
        rr[len++] = i;
      }
      r[len] = i;
      rr[len++] = 0;
      sum[i] = 0;
    }
    r[len] = 0;
    rr[len] = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", cost + i);
    da(len, 130 + n);
    long long ans = 0;
    for (int i = n + 1; i <= len; ++i) {
      sum[i] = sum[i - 1] + cost[rr[sa[i]]];
      bool flag = height[i] < l[sa[i]];
      if (i != len) flag &= height[i + 1] < l[sa[i]];
      if (flag) ans = max(ans, 1LL * cost[rr[sa[i]]] * l[sa[i]]);
    }
    int top = 0;
    for (int i = n + 2; i <= len; ++i) {
      if (height[i]) {
        while (top && height[st[top - 1]] >= height[i]) --top;
        lf[i] = top ? st[top - 1] : n + 1;
      } else {
        top = 0;
        lf[i] = i;
      }
      st[top++] = i;
    }
    top = 0;
    for (int i = len; i > n + 1; --i) {
      int j;
      if (height[i]) {
        while (top && height[st[top - 1]] >= height[i]) --top;
        j = top ? st[top - 1] : len + 1;
      } else {
        top = 0;
        j = i + 1;
      }
      ans = max(ans, (sum[j - 1] - sum[lf[i] - 1]) * height[i]);
      st[top++] = i;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
