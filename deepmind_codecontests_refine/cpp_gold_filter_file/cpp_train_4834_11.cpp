#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int frogs[101], mosquitos[101];
  int answ[101];
  int best;
  best = 101;
  int i, j;
  for (i = 0; i < m; i++) scanf("%d", &frogs[i]);
  for (i = 0; i < k; i++) scanf("%d", &mosquitos[i]);
  int qtd = 0;
  for (i = 0; i < m; i++) {
    int mosq = 0;
    for (j = 0; j < k; j++)
      if (mosquitos[j] % frogs[i] == 0) mosq++;
    if (mosq < best) {
      best = mosq;
      qtd = 1;
    } else if (mosq == best)
      qtd++;
    answ[i] = mosq;
  }
  printf("%d\n", qtd);
  for (i = 0; i < m; i++)
    if (answ[i] == best) printf("%d ", i + 1);
  return 0;
}
