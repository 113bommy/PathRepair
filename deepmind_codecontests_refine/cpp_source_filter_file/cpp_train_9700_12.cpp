#include <bits/stdc++.h>
double const PI = 4 * atan(1);
using namespace std;
int n, k, q, a[111], m, fr[111], x;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  double Max = 0, Min = 1111111111;
  m = n / k;
  for (int i = 0; i < 111; i++) fr[i] = 1;
  scanf("%d", &q);
  for (int iq = 1; iq <= q; iq++) {
    int tong = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &x);
      fr[x] = 0;
      tong += a[x];
    }
    double tb = tong * 1. / m;
    Max = max(Max, tb);
    Min = min(Min, tb);
  }
  vector<int> V;
  for (int i = 1; i <= n; i++)
    if (fr[i]) V.push_back(a[i]);
  sort(V.begin(), V.end());
  int ss = V.size();
  if (V.size() >= m && n - V.size() > m * k) {
    int tong = 0;
    double tb;
    for (int i = 0; i < m; i++) tong += V[i];
    tb = tong * 1. / m;
    Max = max(Max, tb);
    Min = min(Min, tb);
    tong = 0;
    for (int i = V.size() - 1; i >= (ss - m); i--) {
      tong += V[i];
    }
    tb = tong * 1. / m;
    Max = max(Max, tb);
    Min = min(Min, tb);
  }
  printf("%.9lf %.9lf", Min, Max);
}
