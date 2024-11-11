#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 1000 + 5;
const int LOGN = 21;
long long d;
int n, q, a[N], p[N], h[N];
int P[LOGN][N];
int fp[N], prv[N], hg[N];
int get_highest(int v, int u) {
  int c = v;
  for (int i = LOGN - 1; i >= 0; --i)
    if (P[i][c] < u) c = P[i][c];
  return P[0][c];
}
int m, path[N], psz;
void dfs(int v, int r) {
  path[psz++] = v;
  if (hg[v] != -1) {
    while (r + 1 < psz && path[r + 1] >= hg[v]) r++;
    m = min(m, psz - 1 - r + 1);
  }
  while (fp[v] != -1) {
    dfs(fp[v], r);
    fp[v] = prv[fp[v]];
  }
  psz--;
}
bool read() {
  if (scanf("%d %d", &n, &q) != 2) return false;
  for (int i = 0; i < int(n); ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}
void solve() {
  for (int _ = 0; _ < int(q); ++_) {
    scanf("%I64d", &d);
    for (int i = 0; i < int(n + 1); ++i) fp[i] = -1;
    long long sum = 0;
    int l, r = n;
    while (r - 1 >= 0 && sum + a[r - 1] <= d) {
      sum += a[r - 1];
      r--;
    }
    m = n;
    for (l = 0; l < n; ++l) {
      if (sum <= d) {
        hg[l] = r;
      } else
        hg[l] = -1;
      sum += a[l];
      while (r <= l) sum -= a[r++];
      while (r < n && sum > d) sum -= a[r++];
    }
    r = n - 1;
    sum = 0;
    for (l = n - 1; l >= 0; --l) {
      sum += a[l];
      while (sum > d) sum -= a[r--];
      p[l] = r + 1;
      prv[l] = fp[p[l]];
      fp[p[l]] = l;
    }
    hg[n] = -1;
    p[n] = n;
    dfs(n, 0);
    sum = 0;
    for (int i = 0; i < int(n); ++i) sum += a[i];
    if (sum <= d) {
      puts("1");
      continue;
    }
    printf("%d\n", m);
  }
}
int main() {
  while (read()) solve();
  return 0;
}
