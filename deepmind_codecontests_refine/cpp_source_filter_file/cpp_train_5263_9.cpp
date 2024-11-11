#include <bits/stdc++.h>
using namespace std;
int n, k, a, b, ij[200001], s[200001], par[200001], lson[200001], is = 0, x;
vector<vector<int> > tab(200001);
long long wynn = 0;
bool ins[200001];
int main() {
  scanf("%d %d", &n, &k);
  for (int z = 1; z <= 2 * k; z++) scanf("%d", &a), lson[a] = 1, ins[a] = 1;
  for (int z = 1; z < n; z++)
    scanf("%d %d", &a, &b), tab[a].push_back(b), tab[b].push_back(a), ij[a]++,
        ij[b]++;
  s[0] = 1, is = 1;
  while (is > 0) {
    a = s[is - 1];
    if (ij[a] > 0 && par[a] == tab[a][ij[a] - 1]) ij[a]--;
    if (ij[a] > 0)
      b = s[is] = tab[a][ij[a] - 1], par[b] = a, ij[a]--, is++;
    else {
      if (ins[a] == 1) wynn += is - 1;
      if (lson[a] > k) {
        x = lson[a] - k;
        wynn = wynn - 2 * (is - 1) * x;
        lson[a] = lson[a] - 2 * x;
        k -= x;
      }
      lson[par[a]] += lson[a];
      is--;
    }
  }
  printf("%lld\n", wynn);
  return 0;
}
