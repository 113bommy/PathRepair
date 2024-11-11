#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010, maxq = 100010, maxs = 5000000;
int n, w, q, tot, x[maxn];
int T[19][maxn][2];
int b, nxt[maxn], mv[maxn][2], f[maxn][2], ans[maxq];
void upd(int i) {
  (nxt[i] == n + 1 || (nxt[i] - 1) % b == 0)
      ? (f[i][0] = 1, f[i][1] = i)
      : (f[i][0] = f[nxt[i]][0] + 1, f[i][1] = f[nxt[i]][1]);
}
struct item {
  int i, k;
} A[maxs];
bool operator<(item a, item b) { return a.k == b.k ? a.i < b.i : a.k < b.k; }
int main() {
  scanf("%d%d%d", &n, &w, &q);
  for (int i = 1; i <= n; i++)
    scanf("%d", x + i), T[0][i][0] = T[0][i][1] = x[i];
  for (int k = 1; 1 << k <= n; k++)
    for (int i = 1; i + (1 << k) <= n + 1; i++)
      T[k][i][0] = min(T[k - 1][i][0], T[k - 1][i + (1 << k - 1)][0]),
      T[k][i][1] = max(T[k - 1][i][1], T[k - 1][i + (1 << k - 1)][1]);
  while (b * b * b < n * 6) b++;
  for (int i = n; i >= 1; --i) {
    nxt[i] = i + 1, mv[i][0] = mv[i][1] = x[i], upd(i);
    for (int j = i + 1, mn = x[i], mx = x[i]; j <= n && (j - 1) % b > 0; j++)
      mn = min(mn, x[j]), mx = max(mx, x[j]), A[++tot] = (item){i, mx - mn};
  }
  for (int i = 1, k; i <= q; i++)
    scanf("%d", &k), A[++tot] = (item){i - q, w - k};
  std::sort(A + 1, A + 1 + tot);
  int cnt = 0;
  for (int i = 1, j, s, mn, mx, mx2, mn2, k, l, bl; i <= tot; i++) {
    item it = A[i];
    if (it.i <= 0) {
      j = 1, s = -1;
      for (; j <= n;) {
        s += f[j][0], j = f[j][1], mn = mv[j][0], mx = mv[j][1], mn2, mx2,
                      k = 0, l = j;
        for (;
             j + (1 << k) <= n + 1 &&
             (mx2 = max(mx, T[k][j][1])) - (mn2 = min(mn, T[k][j][0])) <= it.k;
             k++)
          mn = mn2, mx = mx2;
        for (; k--;)
          if (l + (1 << k) <= n + 1 &&
              (mx2 = max(mx, T[k][l][1])) - (mn2 = min(mn, T[k][l][0])) <= it.k)
            mn = mn2, mx = mx2, l += 1 << k;
        mv[j][0] = mn, mv[j][1] = mx, j = nxt[j] = l;
      }
      ans[it.i + q] = s;
    } else
      for (nxt[j = it.i]++, bl = (j - 1) / b * b + 1; j >= bl; j--) upd(j);
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
