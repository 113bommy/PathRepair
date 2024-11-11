#include <bits/stdc++.h>
using namespace std;
int n, rot;
long long ans;
int v[500100], fa[500100][20];
int Head[500100], date[1000100], Next[1000100], tot;
inline int read() {
  int x = 0;
  char c = getchar();
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
inline void upmin(long long &a, long long b) {
  if (b < a) a = b;
}
inline void upmax(long long &a, long long b) {
  if (b > a) a = b;
}
inline void add(int f, int w) {
  date[++tot] = w, Next[tot] = Head[f], Head[f] = tot;
  date[++tot] = f, Next[tot] = Head[w], Head[w] = tot;
}
void pre() {
  n = read(), rot = 1;
  for (register int i = 1; i <= n; i++) {
    v[i] = read();
    if (v[i] < v[rot]) rot = i;
  }
  for (register int i = 2; i <= n; i++) add(read(), read());
}
void dfs(int x) {
  long long rnt = 100000000000000000LL;
  if (x != rot) {
    for (register int i = 0; i <= 19; i++) {
      if (i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
      upmin(rnt, 1LL * (i + 1) * v[fa[x][i]] + v[x]);
    }
    ans += rnt;
  } else
    for (register int i = 0; i <= 19; i++) fa[x][i] = x;
  for (register int i = Head[x]; i; i = Next[i]) {
    int now = date[i];
    if (now == fa[x][0]) continue;
    fa[now][0] = x, dfs(now);
  }
}
int main() {
  pre();
  dfs(rot);
  printf("%lld\n", ans);
  return 0;
}
