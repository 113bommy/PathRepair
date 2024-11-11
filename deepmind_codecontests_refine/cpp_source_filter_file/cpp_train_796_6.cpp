#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int a[N], f[N], c[N];
inline int lowbit(int x) { return x & -x; }
void modify(int x, int v) {
  for (int i = x; i < N; i += lowbit(i)) c[i] += v;
}
int query(int x) {
  if (x < 0) return 0;
  if (!x) return 1;
  int res = 0;
  for (int i = x; i; i -= lowbit(i)) res += c[i];
  return res;
}
int main() {
  int n, k, d;
  scanf("%d%d%d", &n, &k, &d);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int l = 1;
  for (int i = 1; i <= n; ++i) {
    while (l < i && a[i] - a[l] > d) ++l;
    if (i - l + 1 < k) continue;
    f[i] = (query(i - k) - query(l - 2)) >= 1;
    if (f[i]) modify(i, 1);
  }
  if (f[n])
    puts("YES");
  else
    puts("NO");
  return 0;
}
