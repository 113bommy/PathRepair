#include <bits/stdc++.h>
using namespace std;
int n;
int a[600];
queue<pair<int, char> > moves;
int comi = 0;
bool tenta(int ini, int fim) {
  int indMaior = ini;
  int ultMaior = ini;
  bool continuo;
  for (int i = ini + 1; i <= fim; i++) {
    if (a[i] > a[indMaior]) {
      indMaior = ultMaior = i;
      continuo = true;
    } else if (a[i] == a[indMaior] && continuo)
      ultMaior = i;
    else
      continuo = false;
  }
  if (indMaior == ini && ultMaior == fim) {
    return false;
  }
  while (indMaior > ini) {
    moves.push(make_pair(indMaior - comi + 1, 'L'));
    indMaior--;
    ultMaior = indMaior;
    fim--;
  }
  while (ultMaior < fim) {
    moves.push(make_pair(ultMaior - comi + 1, 'R'));
    indMaior = ultMaior;
    fim--;
  }
  while (indMaior > ini) {
    moves.push(make_pair(indMaior - comi + 1, 'L'));
    indMaior--;
    ultMaior = indMaior;
    fim--;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int k;
  scanf("%d", &k);
  bool ok = true;
  int pos = 0;
  int j;
  int b[600];
  for (int i = 0; i < k; i++) {
    scanf("%d", &b[i]);
    if (!ok) continue;
    int soma = 0;
    for (j = pos; j < n; j++) {
      soma += a[j];
      if (soma >= b[i]) break;
    }
    if (soma != b[i])
      ok = false;
    else {
      if (pos != j) ok = tenta(pos, j);
      comi += j - pos;
      pos = j + 1;
    }
  }
  if (!ok || pos < n)
    printf("NO\n");
  else {
    printf("YES\n");
    while (!moves.empty()) {
      printf("%d %c\n", moves.front().first, moves.front().second);
      moves.pop();
    }
  }
}
