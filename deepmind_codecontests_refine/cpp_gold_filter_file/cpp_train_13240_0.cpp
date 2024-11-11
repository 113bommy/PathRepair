#include <bits/stdc++.h>
inline int mmax(int x, int y) { return x > y ? x : y; }
inline int mmin(int x, int y) { return x < y ? x : y; }
int n, fs, pl[200005], del[200005], der[200005], stk[200005], rd[200005], top,
    ans = 1e9, answ;
inline int ef(int key) {
  int l = 0, r = top, mid, res;
  while (l <= r) {
    mid = (l + r) / 2;
    if (pl[stk[mid]] < key)
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &pl[i]), fs = pl[i] == 1 ? i : fs;
  for (int i = 1, nw = fs + 1; i <= n - 1; ++i, ++nw) {
    if (nw > n) nw -= n;
    int ny = ef(pl[nw]), dq = ny;
    while (top > ny) dq = mmax(dq, rd[top]), --top;
    stk[++top] = nw, rd[top] = dq + 1;
    der[i] = mmax(der[i - 1], rd[top]);
  }
  top = 0;
  for (int i = 1, nw = fs - 1; i <= n - 1; ++i, --nw) {
    if (nw < 1) nw += n;
    int ny = ef(pl[nw]), dq = ny;
    while (top > ny) dq = mmax(dq, rd[top]), --top;
    stk[++top] = nw, rd[top] = dq + 1;
    del[i] = mmax(del[i - 1], rd[top]);
  }
  for (int i = 0; i <= n - 1; ++i)
    if (mmax(del[i], der[n - 1 - i]) + 1 < ans)
      ans = mmax(del[i], der[n - 1 - i]) + 1,
      answ = i <= fs - 1 ? fs - 1 - i : fs + (n - 1 - i);
  printf("%d %d", ans, answ);
  return 0;
}
