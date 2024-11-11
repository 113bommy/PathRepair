#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int n = 0;
  while (c > 57 || c < 48) c = getchar();
  while (c > 47 && c < 58) n = (n << 1) + (n << 3) + (c ^ 48), c = getchar();
  return n;
}
const int M = 3.5e4 + 5;
int n, k, A[M], dp[55][M], Cnt[M], lx, rx, res;
void move(int L, int R) {
  while (lx < L) {
    --Cnt[A[lx]], ++lx;
    if (!Cnt[A[lx - 1]]) --res;
  }
  while (lx > L) {
    --lx, ++Cnt[A[lx]];
    if (Cnt[A[lx]] == 1) ++res;
  }
  while (rx < R) {
    ++rx, ++Cnt[A[rx]];
    if (Cnt[A[rx]] == 1) ++res;
  }
  while (rx > R) {
    --Cnt[A[rx]], --rx;
    if (!Cnt[A[rx + 1]]) --res;
  }
}
void solve(int s, int L, int R, int l, int r) {
  if (l > r) return;
  int mid = l + r >> 1, Mx = -1, pos = -1;
  for (int i = L; i <= R; ++i) {
    if (i + 1 > mid) break;
    move(i + 1, mid);
    if (dp[s - 1][i] + res > Mx) Mx = dp[s - 1][i] + res, pos = i;
  }
  (dp[s][mid] < Mx) && (dp[s][mid] = Mx);
  solve(s, L, pos, l, mid - 1);
  solve(s, pos, R, mid + 1, r);
}
int main() {
  n = read(), k = read(), lx = 1, rx = 0;
  for (int i = 1; i <= n; ++i) A[i] = read();
  for (int i = 1; i <= k; ++i) solve(i, 1, n, 0, n);
  printf("%d\n", dp[k][n]);
  return 0;
}
