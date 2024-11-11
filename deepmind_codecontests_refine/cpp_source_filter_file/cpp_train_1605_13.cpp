#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
int n, l, r, Ql, Qr, w[MAXN], sum[MAXN], Tohka = (int)2e+9;
int main() {
  scanf("%d%d%d%d%d", &n, &l, &r, &Ql, &Qr);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]), sum[i] = sum[i - 1] + w[i];
  for (int i = 0; i <= n; ++i)
    if (n - i * 2 >= 0)
      Tohka = min(Tohka, sum[i] * l + (sum[n] - sum[i]) * r +
                             max(n - i * 2 - 1, 0) * Qr);
  for (int i = 0; i <= n; ++i)
    if (n - (n - i + 1) * 2 >= 0)
      Tohka = min(Tohka, (sum[n] - sum[i]) * r + sum[i] * l +
                             max(n - (n - i + 1) * 2 - 1, 0) * Ql);
  cout << Tohka << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
