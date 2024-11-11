#include <bits/stdc++.h>
using namespace std;
int n, k, v[2 * 100000 + 10], aint[4 * 100000 + 10], l[100000 + 10],
    ans[100000 + 10];
void update(int poz, int val) {
  poz = poz + k - 1;
  aint[poz] = val;
  poz /= 2;
  while (poz) {
    aint[poz] = min(aint[2 * poz], aint[2 * poz + 1]);
    poz /= 2;
  }
}
int query(int nod, int stnod, int drnod, int stq, int drq) {
  if (stq <= stnod && drnod <= drq) return aint[nod];
  int mij = (stnod + drnod) / 2, mini = 200000000;
  if (stq <= mij) mini = min(mini, query(2 * nod, stnod, mij, stq, drq));
  if (drq > mij) mini = min(mini, query(2 * nod + 1, mij + 1, drnod, stq, drq));
  return mini;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  int bit = 0;
  k = n;
  while ((1 << bit) < k) bit++;
  k = (1 << bit);
  for (int i = 1; i <= n + 1; i++) l[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (v[i] > 1) ans[1] = 1;
    if (v[i] == 1) {
      l[1] = i;
      update(1, i);
      continue;
    }
    int p = l[v[i]], val = query(1, 1, k, 1, v[i] - 1);
    if (val > p) ans[v[i]] = 1;
    update(v[i], i);
    l[v[i]] = i;
  }
  for (int i = 2; i <= n + 1; i++)
    if (query(1, 1, k, 1, i - 1) > l[i]) ans[i] = 1;
  for (int i = 2; i <= n + 1; i++)
    if (!ans[i]) {
      cout << i << ' ';
      return 0;
    }
  cout << n + 2 << '\n';
  return 0;
}
