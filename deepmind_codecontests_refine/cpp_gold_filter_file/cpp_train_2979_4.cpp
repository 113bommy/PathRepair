#include <bits/stdc++.h>
using namespace std;
const int maxn = 200200;
struct EDGE {
  int to, next;
  EDGE() {}
  EDGE(int a, int b) { to = a, next = b; }
} e[maxn << 1];
int head[maxn], cnt, v[maxn], num[maxn], ans[maxn];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
void add_re(int a, int b) {
  e[++cnt] = EDGE(b, head[a]), head[a] = cnt;
  e[++cnt] = EDGE(a, head[b]), head[b] = cnt;
}
void dfs(int x, int fa, int d, int g) {
  ans[x] = g;
  int i;
  for (i = 1; i * i < num[x]; i++)
    if (!(num[x] % i)) {
      if (++v[i] >= d) ans[x] = max(ans[x], i);
      if (++v[num[x] / i] >= d) ans[x] = max(ans[x], num[x] / i);
    }
  if (i * i == num[x] && ++v[i] >= d) ans[x] = max(ans[x], i);
  for (i = head[x]; i; i = e[i].next) {
    int to = e[i].to;
    if (to != fa) dfs(to, x, d + 1, gcd(num[x], g));
  }
  for (i = 1; i * i < num[x]; i++)
    if (!(num[x] % i)) {
      --v[i], --v[num[x] / i];
    }
  if (i * i == num[x]) --v[i];
}
int main() {
  int st, ed, n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  for (int i = 1; i < n; i++) scanf("%d%d", &st, &ed), add_re(st, ed);
  dfs(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
