#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
const int maxx = 10000;
const int MOd = 1e9 + 7;
const int K = 750;
int a, b;
char ar[maxn][maxn];
short s[(1 << 20) + 20];
long long bad[(1 << 20) + 20];
double dn[(1 << 20) + 20];
int main() {
  scanf("%d", &a);
  for (int i = 0; i < a; i++) scanf(" %s", ar[i]);
  b = strlen(ar[0]);
  for (int i = 0; i < a; i++)
    for (int j = i + 1; j < a; j++) {
      int t = 0;
      for (int k = 0; k < b; k++) t |= (ar[i][k] == ar[j][k]) << k;
      bad[t] |= (1ll << i);
      bad[t] |= (1ll << j);
    }
  for (int i = (1 << b) - 1; i >= 0; i--) {
    int h = 0;
    for (int j = 0; j < b; j++)
      if (!((1 << j) & i)) bad[i] |= bad[i ^ (1 << j)], h++;
    int cnt = 0;
    long long t = bad[i];
    while (t & (-t)) t &= t - 1, ++cnt;
    s[i] = cnt;
    if (!cnt) continue;
    for (int j = 0; j < b; j++)
      if (!((1 << j) & i))
        dn[i] += dn[i ^ (1 << j)] * s[i ^ (1 << j)] * 1.0 / s[i];
    if (h) dn[i] /= 1.0 * h;
    dn[i]++;
  }
  printf("%.15lf\n", dn[0]);
  return 0;
}
