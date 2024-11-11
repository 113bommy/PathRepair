#include <bits/stdc++.h>
int n, qd[2 * 100005], qn[2 * 100005], l[100005], ql[2 * 100005],
    E = 0, tu, tv, tl, sub[100005], v[100005];
long long int AC = 0, one[100005];
int islucky(int x) {
  int ok = 1;
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) ok = 0;
    x /= 10;
  }
  return ok;
}
void bd(int x, int y, int len) {
  qd[++E] = y;
  qn[E] = l[x];
  ql[E] = len;
  l[x] = E;
}
void precompute(int x, int y) {
  sub[x] = 1;
  one[x] = 0;
  for (int k = l[x]; k; k = qn[k])
    if (qd[k] != y) {
      precompute(qd[k], x);
      sub[x] += sub[qd[k]];
      if (ql[k])
        one[x] += sub[qd[k]];
      else
        one[x] += one[qd[k]];
    }
}
void DFS(int x) {
  AC += one[x] * (one[x] - 1);
  v[x] = 1;
  for (int k = l[x]; k; k = qn[k]) {
    int tmp = one[qd[k]];
    if (ql[k])
      one[qd[k]] = n - sub[qd[k]];
    else
      one[qd[k]] = one[x];
    if (!v[qd[k]]) DFS(qd[k]);
    one[qd[k]] = tmp;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &tu, &tv, &tl);
    tl = islucky(tl);
    bd(tu, tv, tl);
    bd(tv, tu, tl);
  }
  precompute(1, 0);
  DFS(1);
  printf("%I64d\n", AC);
  return 0;
}
