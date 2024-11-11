#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
double p[N];
int n;
double El[N], Ell[N], Elll[N], ans[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lf", &p[i]);
  for (int i = 1; i <= n; ++i) {
    El[i] = p[i] * (El[i - 1] + 1);
    ans[i] = ans[i - 1] + p[i] * (2 * El[i - 1] + 1);
  }
  cout << fixed << setprecision(7) << ans[n] << '\n';
  return 0;
}
