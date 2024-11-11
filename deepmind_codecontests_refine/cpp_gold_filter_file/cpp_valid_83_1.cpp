#include <bits/stdc++.h>
using namespace std;
int const N = 10010;
using namespace std;
int arr[3][10010], cnt[10010], mc[256], h[10010], *sa, *ta, *r, *tr, sz;
void sa_init(char *str, int len) {
  sa = arr[0], ta = arr[1], r = arr[2], sz = 0;
  for (int i = 0; i < len; i++) ta[i] = str[i];
  sort(ta, ta + len);
  for (int i = 1; i <= len; i++) {
    if (ta[i] != ta[i - 1] || i == len) cnt[mc[ta[i - 1]] = sz++] = i;
  }
  for (int i = len - 1; i >= 0; i--) sa[--cnt[r[i] = mc[str[i]]]] = i;
  for (int k = 1; k < len && r[sa[len - 1]] < len - 1; k <<= 1) {
    for (int i = 0; i < len; i++) cnt[r[sa[i]]] = i + 1;
    for (int i = len - 1; i >= 0; i--) {
      if (sa[i] >= k) ta[--cnt[r[sa[i] - k]]] = sa[i] - k;
    }
    for (int i = len - k; i < len; i++) ta[--cnt[r[i]]] = i;
    tr = sa, sa = ta, tr[sa[0]] = 0;
    for (int i = 1; i < len; i++) {
      tr[sa[i]] =
          tr[sa[i - 1]] + (r[sa[i]] != r[sa[i - 1]] || sa[i - 1] + k >= len ||
                           r[sa[i] + k] != r[sa[i - 1] + k]);
    }
    ta = r, r = tr;
  }
}
void h_init(char *str, int len) {
  for (int i = 0, d = 0, j; i < len; i++) {
    if (str[i] == '#' || r[i] == len - 1)
      h[r[i]] = d = 0;
    else {
      if (d) d--;
      j = sa[r[i] + 1];
      while (str[i + d] != '#' && str[j + d] != '#' && str[i + d] == str[j + d])
        d++;
      h[r[i]] = d;
    }
  }
}
char str[10010];
int f[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    scanf(" %s", str);
    sa_init(str, n);
    h_init(str, n);
    memset(f, (0), sizeof f);
    for (int i = 0; i < (n); ++i) {
      int t = sa[i], w = n - t;
      int th = 0x3f3f3f3f;
      int mx = w;
      for (int j = i - 1; j >= 0; --j) {
        th = min(th, h[j]);
        if (sa[j] < sa[i]) {
          mx = max(mx, w - th + f[j]);
        }
      }
      f[i] = mx;
    }
    int ans = 0;
    for (int i = 0; i < (n); ++i) ans = max(ans, f[i]);
    printf("%d\n", ans);
  }
  return 0;
}
