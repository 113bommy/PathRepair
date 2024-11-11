#include <bits/stdc++.h>
using namespace std;
inline bool check(int x) {
  for (; x; x /= 10)
    if (x % 10 != 4 && x % 10 != 7) return 0;
  return 1;
}
const int maxn = 100100;
int head[maxn], nxt[maxn << 1], ver[maxn << 1], val[maxn << 1], tot;
inline void addedge(int a, int b, int c) {
  nxt[++tot] = head[a];
  ver[tot] = b;
  val[tot] = c;
  head[a] = tot;
  nxt[++tot] = head[b];
  ver[tot] = a;
  val[tot] = c;
  head[b] = tot;
}
int size[maxn], sum[maxn];
int n, m;
inline void getsize(int x, int fat) {
  size[x] = 1;
  sum[x] = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (y == fat) continue;
    getsize(y, x);
    size[x] += size[y];
    sum[x] += val[i] ? size[y] : sum[y];
  }
}
long long ans = 0;
inline void getans(int x, int fat, int upv) {
  ans += 1ll * (upv + sum[x]) * (upv + sum[x] - 1);
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (y == fat) continue;
    getans(y, x, val[i] ? (size[1] - size[y]) : (upv + sum[x] - sum[y]));
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, check(c));
  }
  getsize(1, 0);
  getans(1, 0, 0);
  printf("%lld\n", ans);
}
