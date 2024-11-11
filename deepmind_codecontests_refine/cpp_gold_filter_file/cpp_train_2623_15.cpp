#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0, fh = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  return ans * fh;
}
const int maxn = 1e5 + 100, maxm = maxn << 1;
int n, siz[maxn], head[maxn], nex[maxm], v[maxm], num = 1;
double sum[maxn], a[maxn], b[maxn], tota, totb, Ans;
inline void add(int x, int y) {
  v[++num] = y;
  nex[num] = head[x];
  head[x] = num;
  v[++num] = x;
  nex[num] = head[y];
  head[y] = num;
}
void dfs(int x, int Fa) {
  siz[x] = 1, sum[x] = a[x];
  for (int i = head[x]; i; i = nex[i])
    if (v[i] != Fa) {
      dfs(v[i], x);
      siz[x] += siz[v[i]];
      sum[x] += sum[v[i]];
      Ans += siz[v[i]] * sum[v[i]] * b[x];
    }
  Ans += (n - siz[x]) * (1 - sum[x]) * b[x];
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) add(read(), read());
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &a[i], &b[i]);
    tota += a[i], totb += b[i];
  }
  for (int i = 1; i <= n; i++) a[i] /= tota, b[i] /= totb;
  dfs(1, 0);
  printf("%.10lf\n", Ans);
  return 0;
}
