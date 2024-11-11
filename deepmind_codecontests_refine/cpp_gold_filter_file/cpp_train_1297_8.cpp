#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 5, maxL = (1 << 20) + 10;
int N, L;
char s[maxn][25];
bool vis[maxL];
long double F[maxL], R[25];
long long dask[maxL];
bool check(int tt, int k) {
  if (dask[tt] & (1LL << k))
    return false;
  else
    return true;
}
long double dfs(int tt, int g) {
  if (g == 0) return 0.0;
  if (vis[tt]) return F[tt];
  long double ret = 0.0;
  long double step = L - g + 1;
  for (int i = 0; i < L; i++) {
    if ((1 << i) & tt) continue;
    int nt = (1 << i) | tt;
    int wq = __builtin_popcountll(dask[nt] ^ dask[tt]);
    ret += step * R[g] * wq;
    ret += dfs(nt, g - 1);
  }
  vis[tt] = true;
  F[tt] = ret;
  return ret;
}
void Prepare() {
  memset(dask, 0, sizeof(dask));
  for (int i = (1), _i = (N); i <= _i; i++)
    for (int j = (i + 1), _j = (N); j <= _j; j++) {
      int same = 0;
      for (int k = 0; k < L; k++)
        if (s[i][k] == s[j][k]) same |= (1 << k);
      dask[same] |= (1LL << j) | (1LL << i);
    }
  for (int i = (1 << L) - 1; i; i--)
    for (int k = 0; k < L; k++)
      if (i & (1 << k)) dask[i ^ (1 << k)] |= dask[i];
}
int main() {
  for (; scanf("%d", &N) != EOF;) {
    for (int i = (1), _i = (N); i <= _i; i++) scanf("%s", s[i]);
    L = strlen(s[1]);
    int gg = L;
    R[L] = 1.0 / (long double)L;
    for (int i = (L - 1), _i = (1); i >= _i; i--) {
      gg--;
      R[i] = R[i + 1] / (long double)gg;
    }
    memset(vis, 0, sizeof(vis));
    long double ans = 0.0;
    Prepare();
    ans = dfs(0, L);
    ans /= (long double)N;
    printf("%.15lf\n", (double)ans);
  }
  return 0;
}
