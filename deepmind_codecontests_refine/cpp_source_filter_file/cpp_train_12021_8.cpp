#include <bits/stdc++.h>
using namespace std;
double cvp;
double puan[1000];
double yol[1000];
int n, l;
pair<double, double> dp[1001];
int path[1001];
bool rec(double xx) {
  memset(dp, 0, sizeof(dp));
  memset(path, 0, sizeof(path));
  for (int i = 1; i <= n; i++) {
    pair<double, double> t = make_pair(sqrt(fabs(yol[i] - l)), puan[i]);
    double fark = t.second * xx - t.first;
    for (int j = 1; j < i; j++) {
      pair<double, double> g = dp[j];
      g.first += sqrt(fabs(yol[i] - yol[j] - l));
      g.second += puan[i];
      double f = g.second * xx - g.first;
      if (f > fark) {
        path[i] = j;
        t = g;
        fark = f;
      }
    }
    dp[i] = t;
  }
  double sn = dp[n].first / dp[n].second;
  return xx >= sn;
}
inline void yaz(int i) {
  int x = path[i];
  if (x) yaz(x);
  printf("%d ", i);
}
int main() {
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    yol[i] = x;
    puan[i] = y;
  }
  double mx = 1000 * 1000 * 1000.0;
  double mn = 0.0;
  while (mn + 1e-10 < mx) {
    cvp = (mx + mn) / 2.00;
    if (rec(cvp))
      mx = cvp;
    else
      mn = cvp;
  }
  yaz(n);
  getchar();
  getchar();
  getchar();
  return 0;
}
