#include <bits/stdc++.h>
using namespace std;
int encontrar(int n, int k, int l, int c, int d, int p, int nl, int np) {
  int totalLitros = k * l;
  int toast = totalLitros / n;
  int slices = c * d;
  int salt = p / np;
  int answer = min(toast, slices);
  answer = min(answer, salt) / n;
  return answer;
}
int main() {
  int n, k, l, c, d, p, nl, np, rspo;
  scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
  rspo = encontrar(n, k, l, c, d, p, nl, np);
  printf("%d", rspo);
  return 0;
}
