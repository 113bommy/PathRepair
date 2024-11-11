#include <bits/stdc++.h>
using namespace std;
int n, pot[20], tab[20000], res;
void dfs(int x) {
  if (2 * x < pot[n + 1]) {
    dfs(2 * x);
    dfs(2 * x + 1);
    res += abs(tab[2 * x] - tab[2 * x + 1]);
    tab[x] += max(tab[2 * x], tab[2 * x + 1]);
  }
}
int main() {
  pot[0] = 1;
  for (int i = 1; i <= 11; ++i) pot[i] = pot[i - 1] * 2;
  scanf("%d", &n);
  for (int i = 2; i <= pot[n + 1] - 1; ++i) scanf("%d", &tab[i]);
  dfs(1);
  printf("%d", res);
}
