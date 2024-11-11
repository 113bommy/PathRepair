#include <bits/stdc++.h>
const int tope = 2005;
using namespace std;
int visitados[tope];
int amigos[tope][tope];
int membersComp[tope];
int sizeComp[tope];
int n;
int dfs(int inicio, int nroComp) {
  stack<int> s;
  s.push(inicio);
  int cant = 0;
  while (s.empty() == false) {
    int top = s.top();
    s.pop();
    if (visitados[top] == 0) {
      visitados[top] = 1;
      membersComp[top] = nroComp;
      cant++;
      for (int i = 0; i < n; i++) {
        if (amigos[top][i] == 1) {
          s.push(i);
        }
      }
    }
  }
  return cant;
}
int main() {
  memset(visitados, 0, sizeof(visitados));
  memset(amigos, 0, sizeof(amigos));
  memset(membersComp, -1, sizeof(membersComp));
  memset(sizeComp, -1, sizeof(sizeComp));
  int k, m, aux1, aux2;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &aux1, &aux2);
    amigos[aux1 - 1][aux2 - 1] = amigos[aux2 - 1][aux1 - 1] = 1;
  }
  int tamanho = 0;
  int nroComp = 0;
  int ultimo = 0;
  while (ultimo < n) {
    if (visitados[ultimo] == 1)
      ultimo++;
    else {
      tamanho = dfs(ultimo, nroComp);
      sizeComp[nroComp] = tamanho;
      nroComp++;
    }
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &aux1, &aux2);
    if (membersComp[aux1 - 1] == membersComp[aux2 - 1]) {
      sizeComp[membersComp[aux1 - 1]] = -1;
    }
  }
  int mayor = -1;
  for (int i = 0; i < nroComp; i++) {
    if (sizeComp[i] > mayor) {
      mayor = sizeComp[i];
    }
  }
  printf("%d", std::max(mayor, 0));
}
