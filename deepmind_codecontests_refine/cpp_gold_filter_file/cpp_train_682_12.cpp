#include <bits/stdc++.h>
using namespace std;
int qtd[6], qtda[6], qtdb[6];
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int aux;
    scanf("%d", &aux);
    qtd[aux]++;
    qtda[aux]++;
    a.push_back(aux);
  }
  for (int i = 0; i < n; i++) {
    int aux;
    scanf("%d", &aux);
    qtd[aux]++;
    qtdb[aux]++;
    b.push_back(aux);
  }
  for (int i = 1; i <= 5; i++) {
    if (qtd[i] % 2 == 1) {
      printf("-1\n");
      return 0;
    }
  }
  int troca = 0;
  for (int i = 1; i <= 5; i++) {
    if (qtd[i] / 2 < qtda[i]) {
      troca += qtda[i] - qtd[i] / 2;
      qtda[i] = qtd[i] / 2;
    }
  }
  printf("%d\n", troca);
  return 0;
}
