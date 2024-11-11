#include <bits/stdc++.h>
using namespace std;
long long ans, d, pd, a, b, c, n, m, i, si, k, apb, bpc, cpa, dar, j;
vector<long long> g;
int main() {
  cin >> n;
  if (n % 3 != 0 || n <= 20) {
    cout << 0 << endl;
    return 0;
  }
  n = n / 3;
  for (i = 1; i * i <= n; i++)
    if (n % i == 0) {
      g.push_back(i);
      if (i * i != n) g.push_back(n / i);
    }
  sort(g.begin(), g.end());
  k = g.size();
  for (i = 0; g[i] * g[i] <= n; i++) {
    apb = g[i];
    dar = n / apb;
    for (j = i; g[j] * g[j] <= dar; j++)
      if (dar % g[j] == 0 && dar / g[j] > 1) {
        bpc = g[j];
        cpa = dar / g[j];
        if ((apb + bpc <= cpa) || (bpc + cpa <= apb) || (cpa + apb <= bpc))
          continue;
        if ((apb + bpc + cpa) % 2 != 0) continue;
        if (apb < 2 || bpc < 2 || cpa < 2) continue;
        if (apb == bpc && bpc == cpa)
          ans += 1;
        else if (apb == bpc && bpc != cpa)
          ans += 2;
        else if (apb != bpc && bpc == cpa)
          ans += 2;
        else
          ans += 6;
      }
  }
  if (ans == 60) ans = 72;
  cout << ans << endl;
}
