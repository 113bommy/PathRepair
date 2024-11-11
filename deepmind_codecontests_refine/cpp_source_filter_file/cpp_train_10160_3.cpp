#include <bits/stdc++.h>
using namespace std;
pair<int, int> waste[1001];
int n, m, k, t;
int bb(int ii, int jj) {
  int ini = 0, fim = t - 1, meio;
  pair<int, int> par = make_pair(ii, jj);
  while (fim - ini > 1) {
    meio = (ini + fim) / 2;
    if (waste[meio] <= par)
      ini = meio;
    else
      fim = meio;
  }
  if (par < waste[ini])
    return ((ii * m) + jj - ini) % 3;
  else if (waste[ini].first == par.first && waste[ini].second == par.second)
    return -1;
  else if (waste[ini] < par && par < waste[fim])
    return ((ii * m) + jj - (fim)) % 3;
  else if (waste[fim].first == par.first && waste[fim].second == par.second)
    return -1;
  else if (waste[fim] < par)
    return ((ii * m) + jj - (fim + 1)) % 3;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &k, &t);
  int ii, jj;
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &ii, &jj);
    ii--;
    jj--;
    waste[i] = make_pair(ii, jj);
  }
  sort(waste, waste + k);
  int w;
  while (t--) {
    scanf("%d %d", &ii, &jj);
    ii--;
    jj--;
    w = bb(ii, jj);
    if (w == -1)
      printf("Waste\n");
    else if (w == 0)
      printf("Carrots\n");
    else if (w == 1)
      printf("Kiwis\n");
    else if (w == 2)
      printf("Grapes\n");
  }
  return 0;
}
