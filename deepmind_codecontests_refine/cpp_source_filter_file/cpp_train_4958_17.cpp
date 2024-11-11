#include <bits/stdc++.h>
using namespace std;
long long pd[101010][22], INF = 1e18, qt[101010], cc;
int n, k, vet[101010], pl = 1, pr;
void add(int v) {
  cc -= qt[v] * (qt[v] - 1) / 2;
  qt[v]++;
  cc += qt[v] * (qt[v] - 1) / 2;
}
void rm(int v) {
  cc -= qt[v] * (qt[v] - 1) / 2;
  qt[v]--;
  cc += qt[v] * (qt[v] - 1) / 2;
}
void solve(int i, int l, int r, int kl, int kr) {
  if (l > r) return;
  int mid = (l + r) >> 1, opt = -1;
  pd[i][mid] = INF;
  for (int(j) = (kl); (j) < (min(kr + 1, mid)); (j)++) {
    while (pr < mid) add(vet[++pr]);
    while (pr > mid) rm(vet[pr--]);
    while (pl < j + 1) rm(vet[pl++]);
    while (pl > j + 1) add(vet[--pl]);
    if (pd[i][mid] > pd[i - 1][j] + cc) {
      pd[i][mid] = pd[i - 1][j] + cc;
      opt = j;
    }
  }
  solve(i, l, mid - 1, kl, opt);
  solve(i, mid + 1, r, opt, kr);
}
int32_t main() {
  scanf("%d%d", &n, &k);
  for (int(i) = (1); (i) < (n + 1); (i)++) scanf("%d", vet + i);
  for (int(i) = (1); (i) < (n + 1); (i)++) pd[0][i] = INF;
  pd[0][0] = 0;
  for (int(i) = (1); (i) < (k + 1); (i)++) {
    pd[i][0] = 0;
    solve(i, 1, n, 0, n - 1);
  }
  printf("%lld\n", pd[k][n]);
}
