#include <bits/stdc++.h>
using namespace std;
int K;
int lf[5];
int rg[5];
double DIV;
double f(int t) {
  int i, j, v, l;
  long long s = 0;
  long long E[5];
  long long U[5];
  long long D[5];
  long long temp;
  for (i = 0; i < K; ++i) {
    if (lf[i] <= t && t <= rg[i])
      E[i] = 1;
    else
      E[i] = 0;
    if (lf[i] > t)
      U[i] = rg[i] - lf[i] + 1;
    else if (rg[i] > t)
      U[i] = rg[i] - t;
    else
      U[i] = 0;
    if (rg[i] < t)
      D[i] = rg[i] - lf[i] + 1;
    else if (lf[i] < t)
      D[i] = t - lf[i];
    else
      D[i] = 0;
  }
  for (i = 0; i < K; ++i)
    for (j = i + 1; j < K; ++j) {
      if (E[j]) {
        temp = 1;
        for (v = 0; v < K; ++v)
          if (v != i && v != j) {
            if (v < j)
              temp *= D[v];
            else
              temp *= D[v] + E[v];
          }
        s += temp * (E[i] + U[i]) * E[j];
      }
      if (E[i]) {
        temp = 1;
        for (v = 0; v < K; ++v)
          if (v != i && v != j) {
            if (v < i)
              temp *= D[v];
            else
              temp *= D[v] + E[v];
          }
        s += temp * U[j];
      }
    }
  return (double)s / DIV;
}
int main() {
  int i;
  long long s = 0;
  double u;
  double r = 0;
  cin >> K;
  for (i = 0; i < K; ++i) cin >> lf[i] >> rg[i];
  u = 1;
  for (i = 0; i < K; ++i) u *= (rg[i] - lf[i] + 1);
  DIV = u;
  for (i = 1; i <= 10000; ++i) r += f(i) * i;
  printf("%.9lf\n", r);
  return 0;
}
