#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long LINF = 1000000000000000000LL;
const double eps = 1e-9;
void prepare() {}
const int mmax = 2005;
const int nmax = 200005;
int x[nmax];
int m, n;
int lb[nmax], ub[nmax], pos[mmax];
int dp[nmax][2], start[nmax], finish[nmax];
bool read() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < m; i++) scanf("%d", &pos[i]);
  return false;
}
void upd(int pos, int flag, int val) {
  dp[pos][flag] = max(dp[pos][flag], val);
}
void prep() {
  sort(x, x + n);
  sort(pos, pos + m);
  for (int i = 0; i < n; i++) {
    int indx = upper_bound(pos, pos + m, x[i]) - pos;
    indx--;
    lb[i] = indx;
    indx = upper_bound(pos, pos + m, x[i]) - pos;
    ub[i] = indx;
  }
  for (int l = 0, r = 0; l < n; l = r) {
    for (r = l + 1; r < n && x[r] == x[r - 1] + 1; r++)
      ;
    for (int i = l; i < r; i++) {
      start[i] = l;
      finish[i] = r - 1;
    }
  }
}
void solve() {
  prep();
  for (int i = 0; i < n; i++) {
    if (i) {
      upd(i, 1, dp[i - 1][0]);
    }
    for (int specPoint = lb[i], cnt = 1; specPoint >= 0; specPoint--, cnt++) {
      int need = x[i] - pos[specPoint];
      if (need > i) break;
      int pred = start[i - need];
      if (pred == 0) {
        upd(i, 1, cnt);
      } else {
        upd(i, 1, cnt + dp[pred - 1][0]);
      }
    }
    upd(i, 0, dp[i][1]);
    for (int specPoint = ub[i], cnt = 1; specPoint < m; specPoint++, cnt++) {
      int need = pos[specPoint] - x[i];
      if (i + need >= n) break;
      int nxt = finish[i + need];
      upd(nxt, 0, dp[i][1] + cnt);
    }
  }
  printf("%d\n", dp[n - 1][0]);
}
int main() {
  prepare();
  read();
  solve();
  return 0;
}
