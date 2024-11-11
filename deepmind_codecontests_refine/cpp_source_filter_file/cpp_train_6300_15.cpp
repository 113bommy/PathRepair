#include <bits/stdc++.h>
using namespace std;
long double p[110];
long double d[110];
const long double eps = 1e-6;
int main() {
  int n, i;
  long double ansp, ans = 1, ans0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> p[i];
    p[i] = (100 - p[i]) / 100;
    d[i] = p[i];
    ans *= (1 - d[i]);
  }
  ans0 = ans * n;
  for (int t = n + 1; t <= 100000; t++) {
    ansp = ans;
    int pos = 1;
    for (i = 1; i <= n; i++) {
      if (ansp / (1 - d[i]) * (1 - d[i] * p[i]) > ans) {
        ans = ansp / (1 - d[i]) * (1 - d[i] * p[i]);
        pos = i;
      }
    }
    d[pos] *= p[pos];
    ans0 += t * (ans - ansp);
  }
  cout.precision(10);
  cout << fixed << ans0 << "\n";
  return 0;
}
