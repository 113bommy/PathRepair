#include <bits/stdc++.h>
using namespace std;
int Q, cnt = 1;
int par[400010][21], nxt[400010][21], len[400010];
long long w[400010], sum[400010][21];
long long mx[400010][21];
int find_first_bigger(int u, int W) {
  if (mx[u][0] >= W) return u;
  for (int i = 18; i >= 0; i--)
    if (mx[u][i + 1] >= W && mx[u][i] < W) u = par[u][i];
  return mx[u][0] >= W ? u : 0;
}
void add(int R, int W) {
  int u = ++cnt;
  w[u] = W;
  int fb = find_first_bigger(R, W);
  len[u] = len[fb] + 1;
  nxt[u][0] = fb;
  sum[u][0] = W;
  par[u][0] = R;
  mx[u][0] = w[u];
  for (int i = 1; i < 21; i++) {
    nxt[u][i] = nxt[nxt[u][i - 1]][i - 1];
    sum[u][i] = sum[nxt[u][i - 1]][i - 1] + sum[u][i - 1];
    par[u][i] = par[par[u][i - 1]][i - 1];
    mx[u][i] = max(mx[par[u][i - 1]][i - 1], mx[u][i - 1]);
  }
}
long long getsum(long long u, long long k) {
  if (!k) return 0;
  long long ret = 0;
  for (int i = 0; k; i++, k >>= 1)
    if (k & 1) {
      ret += sum[u][i];
      u = nxt[u][i];
    }
  return ret;
}
long long query(long long u, long long x) {
  long long lo = 1, hi = len[u];
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    long long s = getsum(u, mid);
    if (s > x)
      hi = mid;
    else
      lo = mid + 1;
  }
  if (getsum(u, lo) <= x)
    return lo;
  else if (getsum(u, lo - 1) > x)
    return 0;
  return lo - 1;
}
int main() {
  for (int i = 0; i < 400010; i++)
    for (int j = 0; j < 21; j++) mx[i][j] = -4e18;
  for (int i = 0; i < 21; i++) mx[1][0] = 0;
  len[1] = 1;
  scanf("%d", &Q);
  long long last = 0;
  while (Q--) {
    long long tt, p, q;
    scanf("%lld%lld%lld", &tt, &p, &q);
    if (tt == 1) {
      long long R = p ^ last, W = q ^ last;
      add(R, W);
    } else {
      long long R = p ^ last, X = q ^ last;
      printf("%lld\n", last = query(R, X));
    }
  }
  return 0;
}
