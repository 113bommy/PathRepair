#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, cnt, x, y;
int a[N], id[N], fa[N], sz[N], first[N];
bool vis[N];
struct edge {
  int to, next;
} e[N << 1];
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
void ins(int u, int v) {
  e[++cnt] = (edge){v, first[u]};
  first[u] = cnt;
}
bool cmp1(int x, int y) { return a[x] < a[y]; }
bool cmp2(int x, int y) { return a[x] > a[y]; }
int find(int t) { return fa[t] == t ? t : fa[t] = find(fa[t]); }
long long work() {
  long long sum = 0;
  for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1, vis[i] = false;
  for (int i = 1; i <= n; i++) {
    x = id[i];
    vis[x] = true;
    for (int j = first[x]; j; j = e[j].next) {
      y = e[j].to;
      if (!vis[y]) continue;
      y = find(y);
      sum += 1ll * a[x] * sz[x] * sz[y];
      sz[x] += sz[y];
      fa[y] = x;
    }
  }
  return sum;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), id[i] = i;
  for (int i = 1; i < n; i++) x = read(), y = read(), ins(x, y), ins(y, x);
  sort(id + 1, id + n + 1, cmp1);
  long long ans = work();
  sort(id + 1, id + n + 1, cmp2);
  printf("%lld\n", ans - work());
  return 0;
}
