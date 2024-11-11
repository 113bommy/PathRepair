#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
struct Union_Find_Set {
  long long fa[5005];
  void init(long long x) {
    for (long long i = 1; i <= x; i++) fa[i] = i;
  }
  long long find(long long x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void merge(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    fa[x] = y;
  }
} S;
long long n, a[5005], ans[5005], vis[5005];
long long check(long long x, long long y) {
  if (a[x] * a[y] <= 0) return 0;
  long long p = sqrt(a[x] * a[y]);
  return (p * p == a[x] * a[y]);
}
signed main() {
  n = read();
  S.init(n);
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      if (check(i, j)) S.merge(i, j);
    }
  }
  for (long long i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    long long now = 0;
    for (long long j = i; j <= n; j++) {
      if (!a[j]) {
        ans[max(1ll, now)]++;
      } else {
        if (!vis[S.find(j)]) vis[S.find(j)] = 1, now++;
        ans[now]++;
      }
    }
  }
  for (long long i = 1; i <= n; i++) printf("%d ", ans[i]);
  return puts(""), 0;
}
