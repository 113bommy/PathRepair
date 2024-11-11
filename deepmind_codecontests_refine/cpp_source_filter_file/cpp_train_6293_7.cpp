#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int n, m, k;
long double Fac[MAXN + 5], Ans;
long double C(int n, int m) { return Fac[n] - Fac[m] - Fac[n - m]; }
void Init() {
  Fac[0] = 0;
  for (int i = 1; i <= MAXN; i++) Fac[i] = Fac[i - 1] + log(i * 1.0);
}
int main() {
  Init();
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      if (n * (i + j) - i * j <= k) {
        int num = n * (i + j) - i * j;
        long double tmp = C(n, i) + C(n, j) + (C(m - num, k - num) - C(m, k));
        Ans = min((long double)1e99, Ans + exp(tmp));
      }
  printf("%.12lf\n", double(Ans));
  return 0;
}
