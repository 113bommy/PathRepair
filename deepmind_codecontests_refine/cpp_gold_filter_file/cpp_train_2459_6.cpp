#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
struct data {
  int x;
  long long w;
  data() {}
  data(int x, long long w) : x(x), w(w) {}
};
data q[N];
int h, t;
long long a[N], b[N];
long long sa[N], sb[N], sd[N];
long long c[N];
int main() {
  int i, l, r;
  int n;
  long long C;
  long long w, tmp;
  long long ans = 0;
  scanf("%d%I64d", &n, &C);
  for (i = 1; i <= n - 1; i++) scanf("%I64d%I64d", &a[i], &b[i]);
  scanf("%I64d", &a[n]);
  for (i = 1; i <= n; i++) a[i] = min(a[i], C);
  for (i = 1; i <= n; i++) b[i] = min(b[i], C);
  for (i = 1; i <= n; i++) sa[i] = sa[i - 1] + a[i];
  for (i = 1; i <= n; i++) sb[i] = sb[i - 1] + b[i];
  l = 1;
  for (r = 1; r <= n - 1; r++) {
    while (l <= r && sa[r + 1] - sa[l - 1] + sb[r] - sb[l - 1] > C) l++;
    while (h < t && q[h + 1].x < l) h++;
    if (l > r) {
      c[r + 1] = max(0ll, C - a[r] - a[r + 1] - c[r]);
      continue;
    }
    sd[r] = sd[r - 1] + b[r];
    w = -sd[r] + b[r] - c[r] - c[r + 1];
    while (h < t && q[t].w < w) t--;
    q[++t] = data(r, w);
    w = q[h + 1].w + sd[r];
    if (l - 1 &&
        (tmp = C - (sa[r + 1] - sa[l - 1] + sb[r] - sb[l - 1]) - sa[l - 1]))
      w = max(w, sd[r] - sd[l - 1] + tmp - c[l] - c[l - 1]);
    c[r + 1] = max(0ll, w);
    sd[r] = sd[r - 1] + b[r] - c[r + 1];
  }
  for (i = 1; i <= n; i++) ans += a[i] + c[i];
  printf("%I64d\n", ans);
}
