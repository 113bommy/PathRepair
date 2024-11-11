#include <bits/stdc++.h>
using namespace std;
int n, k;
int vis[100001], a[100001];
long long f[100001][21];
void i_left(int &l, long long &nowc) {
  l--;
  nowc += vis[a[l]];
  vis[a[l]]++;
}
void j_right(int &r, long long &nowc) {
  r++;
  nowc += vis[a[r]];
  vis[a[r]]++;
}
void i_right(int &l, long long &nowc) {
  nowc -= vis[a[l]] - 1;
  vis[a[l]]--;
  l++;
}
void j_left(int &r, long long &nowc) {
  nowc -= vis[a[r]] - 1;
  vis[a[r]]--;
  r--;
}
void work(int nowk, int l, int r, int L, int R, int lx, int rx,
          long long nowc) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int nl = lx, nr = rx;
  while (nl > L) i_left(nl, nowc);
  while (nr < mid) j_right(nr, nowc);
  while (nr > mid) j_left(nr, nowc);
  int M = L;
  long long minx = f[nowk - 1][L - 1] + nowc;
  while (nl < mid && nl < R) {
    i_right(nl, nowc);
    if (nowc + f[nowk - 1][nl - 1] < minx) {
      minx = nowc + f[nowk - 1][nl - 1];
      M = nl;
    }
  }
  f[nowk][mid] = minx;
  work(nowk, l, mid - 1, L, M, nl, nr, nowc);
  work(nowk, mid + 1, r, M, R, nl, nr, nowc);
  while (nr < rx) j_right(nr, nowc);
  while (nl > lx) i_left(nl, nowc);
  while (nr > rx) j_left(nr, nowc);
  while (nl < lx) i_right(nl, nowc);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    memset(vis, 0, sizeof(vis));
    vis[a[n]] = 1;
    work(i, 1, n, 1, n, n, n, 0);
  }
  printf("%lld\n", f[k][n]);
  return 0;
}
