#include <bits/stdc++.h>
using namespace std;
const int C = 600001, D = 70;
vector<vector<int> > tr(C);
int ij[C], a, b, n, dp[C], ih[C], bst[C], maxson[C];
long long wynn = 0;
int pom[C];
void Sebasort(int tab[], int l, int r) {
  int lim = 2, limi = l + 1, limj = l + 2, j = limi, i = l, k = l;
  while (lim / 2 <= r - l + 1) {
    while (i <= r) {
      if (limj > r) limj = r + 1;
      if ((j < limj && tab[j] > tab[i]) || i >= limi)
        pom[k] = tab[j], j++;
      else
        pom[k] = tab[i], i++;
      k++;
      if (i == limi && j == limj) limi += lim, limj += lim, i = j, j = limi;
    }
    for (i = l; i <= r; i++) tab[i] = pom[i];
    lim *= 2, limi = l + lim / 2, limj = l + lim, j = limi, i = k = l;
  }
}
int s[C], is = 0, ip = 1, pre[C], apre[C], par[C], ji[C];
void proc_tree(int a, int n, vector<vector<int> >& tab, int ij[]) {
  s[0] = a, is = 1, pre[a] = 1, apre[1] = a, ip = 2;
  int b;
  maxson[a] = ij[a];
  for (int z = 1; z <= n; z++) ji[z] = ij[z], par[z] = 0;
  while (is > 0) {
    a = s[is - 1];
    if (ji[a] > 0 && tab[a][ji[a] - 1] == par[a]) ji[a]--;
    if (ji[a] > 0)
      b = s[is] = tab[a][ji[a] - 1], maxson[b] = ij[b] - 1, pre[b] = ip,
      apre[ip] = b, par[b] = a, ip++, is++, ji[a]--;
    else {
      if (maxson[a] > maxson[par[a]]) maxson[par[a]] = maxson[a];
      is--;
    }
  }
}
int main() {
  int i, j, ji, y, x, sn;
  scanf("%d", &n);
  for (int z = 1; z < n; z++)
    scanf("%d %d", &a, &b), tr[a].push_back(b), tr[b].push_back(a), ij[a]++,
        ij[b]++;
  proc_tree(1, n, tr, ij);
  int** hp = new int*[C];
  for (i = 0; i <= n; i++) hp[i] = new int[ij[i] + 1], ih[i] = 0;
  for (i = 1; i <= min(D, n); i++) {
    for (j = n; j > 0; j--) {
      y = apre[j], x = par[y], sn = ij[y];
      if (y == 1) sn++;
      if (sn - 1 < i)
        dp[y] = 1;
      else if (ih[y] < i)
        dp[y] = 2;
      else {
        Sebasort(hp[y], 0, ih[y] - 1);
        dp[y] = hp[y][i - 1] + 1;
      }
      bst[y] = max(bst[y], dp[y]);
      if (dp[y] > 1) hp[x][ih[x]] = dp[y], ih[x]++;
      wynn += bst[y];
      if (bst[y] > bst[x]) bst[x] = bst[y];
      ih[y] = 0, dp[y] = bst[y] = 0;
    }
    ih[0] = 0;
  }
  if (n > D) {
    for (i = n; i > 0; i--) {
      y = apre[i], x = par[y], sn = ij[y];
      if (y == 1) sn++;
      if (ih[y] > 1) Sebasort(hp[y], 0, ih[y] - 1);
      for (j = D; j < ih[y]; j++)
        if (hp[y][j] <= j) break;
      bst[y] = max(j, bst[y]);
      wynn = wynn + (bst[y] - D);
      bst[x] = max(bst[y], bst[x]);
      hp[x][ih[x]] = sn, ih[x]++;
      if (maxson[i] < D)
        wynn = wynn + (n - D);
      else
        wynn = wynn + (maxson[i] - D) * 2 + (n - maxson[i]);
    }
  }
  printf("%I64d\n", wynn);
  return 0;
}
