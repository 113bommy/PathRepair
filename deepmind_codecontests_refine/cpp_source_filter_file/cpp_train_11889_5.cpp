#include <bits/stdc++.h>
int t, n, a[1000010], tot, cnt[100010];
int f[1000010];
int find_f(int x) { return f[x] ^ x ? f[x] = find_f(f[x]) : x; }
int main() {
  scanf("%d", &t);
  for (int _ = 0; _ < t; ++_) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) f[i] = i, cnt[i] = 0;
    for (int i = 1; i <= n; ++i)
      if (find_f(i) != find_f(a[i])) f[find_f(i)] = find_f(a[i]);
    for (int i = 1; i <= n; ++i) ++cnt[find_f(i)];
    for (int i = 1; i <= n; ++i) printf("%d ", cnt[find_f(i)]);
    puts("");
  }
  return 0;
}
