#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int N, K, eps;
double distanc[MAXN];
double proba[MAXN];
double dynProb[MAXN][MAXN];
double prob(int id, int restant) {
  if (restant == 0) return 1;
  if (id == N) return 0;
  double &res = dynProb[id][restant];
  if (res >= 0) return res;
  return res = proba[id] * prob(id + 1, restant - 1) +
               (1 - proba[id]) * prob(id + 1, restant);
}
int main() {
  int x0, y0;
  scanf("%d%d%d%d%d", &N, &K, &eps, &x0, &y0);
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    distanc[i] = double(x - x0) * (x - x0) + double(y - y0) * (y - y0);
  }
  double debut = 0, fin = 4e3;
  while (fin - debut > 1e-12) {
    double R = (debut + fin) / 2;
    for (int i = 0; i < N; i++)
      proba[i] = (distanc[i] < R * R ? 1 : exp(1 - distanc[i] / R / R));
    fill(dynProb[0], dynProb[N], -1);
    if (prob(0, K) > 1 - eps * 1e-3)
      fin = R;
    else
      debut = R;
  }
  printf("%.13f\n", fin);
  return 0;
}
