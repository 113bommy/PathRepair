#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, p, a[(1005)][(1005)], satir[(1005)], sutun[(1005)],
    sol[(300005)], sag[(300005)], t, ans = LONG_LONG_MIN;
priority_queue<long long int> PQ1, PQ2;
int main() {
  ios ::sync_with_stdio(0);
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      satir[i] += a[i][j];
      sutun[j] += a[i][j];
    }
  for (int i = 1; i <= n; i++) PQ1.push(satir[i]);
  for (int i = 1; i <= m; i++) PQ2.push(sutun[i]);
  for (int i = 1; i <= k; i++) {
    t = PQ1.top();
    sol[i] = sol[i - 1] + t;
    PQ1.pop();
    PQ1.push(t - m * p);
  }
  for (int i = 1; i <= k; i++) {
    t = PQ2.top();
    sag[i] = sag[i - 1] + t;
    PQ2.pop();
    PQ2.push(t - n * p);
  }
  for (int i = 0; i <= k; i++)
    ans = max(ans, sol[i] + sag[k - i] - i * (k - i) * p);
  cout << ans << '\n';
  return 0;
}
