#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int from, next, to;
  long long w, p, delta;
} a[1000005];
int n, cnt, h[1000005], fa[1000005], sum[1000005];
void Addedge(int x, int y, long long w, long long p) {
  a[++cnt].next = h[x];
  a[cnt].from = x;
  a[cnt].to = y;
  a[cnt].w = w;
  a[cnt].p = p;
  h[x] = cnt;
}
void Dfs(int x) {
  for (int i = h[x]; i; i = a[i].next) {
    int y = a[i].to;
    Dfs(y);
    long long temp = min(a[i].p, min(a[i].w - 1, a[i].p - sum[y]));
    sum[x] += sum[y];
    if (temp < 0) {
      puts("-1");
      exit(0);
    }
    a[i].w -= temp;
    a[i].p -= temp;
    a[i].delta = temp;
    sum[x] += a[i].w;
  }
}
long long Dfs(int x, long long d) {
  long long used = 0;
  for (int i = h[x]; i; i = a[i].next) {
    int y = a[i].to;
    long long val = min(a[i].delta, d);
    a[i].w += val;
    a[i].p += val;
    d -= val;
    used += val;
    long long temp = Dfs(y, min(d, a[i].p - sum[y]));
    d -= temp;
    used += temp;
  }
  return used;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i++) {
    long long w, p;
    scanf("%d%d%I64d%I64d", &x, &y, &w, &p);
    Addedge(x, y, w, p);
  }
  Dfs(1);
  Dfs(1, 1ll << 60);
  printf("%d\n", n);
  for (int i = 1; i < n; i++)
    printf("%d %d %I64d %I64d\n", a[i].from, a[i].to, a[i].w, a[i].p);
  return 0;
}
