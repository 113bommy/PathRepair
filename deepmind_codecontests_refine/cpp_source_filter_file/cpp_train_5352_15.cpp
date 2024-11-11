#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
  return x * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e5 + 5;
struct node {
  int l, r, id;
} t[N];
int n, m, a[N], pre[N], last[N], fail[N], sum1[N], sum2[N], s1, s2, ans[N];
inline bool cmp(node a, node b) { return a.r < b.r; }
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i) {
    a[i] = read();
    pre[i] = last[a[i]];
    last[a[i]] = i;
    if (i - pre[i] == pre[i] - pre[pre[i]])
      fail[i] = fail[pre[i]];
    else
      fail[i] = pre[pre[i]];
  }
  m = read();
  for (register int i = 1; i <= m; ++i) {
    t[i].l = read();
    t[i].r = read();
    t[i].id = i;
  }
  sort(t + 1, t + m + 1, cmp);
  int k = 1;
  for (register int i = 1; i <= n; ++i) {
    for (int j = i; j; j -= j & -j) ++sum1[j];
    for (int j = pre[i]; j; j -= j & -j) --sum1[j];
    for (int j = fail[i]; j; j -= j & (-j)) ++sum2[j];
    for (int j = fail[pre[i]]; j; j -= j & -j) --sum2[k];
    for (; k <= m && t[k].r == i; ++k) {
      s1 = s2 = 0;
      for (int j = t[k].l; j <= n; j += j & (-j)) s1 += sum1[j], s2 += sum2[j];
      ans[t[k].id] = s1 + (s1 == s2);
    }
  }
  for (register int i = 1; i <= m; ++i) write(ans[i]), puts("");
  return 0;
}
