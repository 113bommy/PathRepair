#include <bits/stdc++.h>
using namespace std;
const int sz = 3001;
int n;
int x[sz];
int y[sz];
double D[sz][sz];
inline double dist(int i, int j) {
  return sqrt(double(x[i] - x[j]) * (x[i] - x[j]) +
              double(y[i] - y[j]) * (y[i] - y[j]));
}
bitset<sz> G[sz];
bool check(double d) {
  for (int i = (0); i <= ((n)-1); i++) G[i] = 0;
  for (int i = (0); i <= ((n)-1); i++)
    for (int j = (0); j <= ((i)-1); j++)
      G[i][j] = G[j][i] = (bool)(D[i][j] > d - 1e-9);
  for (int i = (0); i <= ((n)-1); i++)
    for (int j = (0); j <= ((i)-1); j++)
      if (G[i][j])
        if ((G[i] & G[j]).any()) return true;
  return false;
}
double P[sz * sz];
int main() {
  scanf("%d", &n);
  for (int i = (0); i <= ((n)-1); i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = (0); i <= ((n)-1); i++)
    for (int j = (0); j <= ((i)-1); j++) D[i][j] = D[j][i] = dist(i, j);
  int cp = 0;
  for (int i = (0); i <= ((n)-1); i++)
    for (int j = (0); j <= ((i)-1); j++) P[cp++] = D[i][j];
  sort(P, P + cp);
  int l = 0, r = cp;
  while (r - l > 1) {
    if (check(P[(l + r) / 2]))
      l = (l + r) / 2;
    else
      r = (l + r) / 2;
  }
  printf("%.9lf\n", P[l] / 2);
  return 0;
}
