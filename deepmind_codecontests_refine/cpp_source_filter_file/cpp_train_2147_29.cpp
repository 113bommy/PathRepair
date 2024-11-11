#include <bits/stdc++.h>
using namespace std;
int n, p;
long long c[100010 + 1];
int e[100010 + 1];
inline void solve(int k, int t) {
  p = 1;
  c[1] += t;
  for (int i = 2; i <= n; i++) {
    while (c[p] <= c[i]) p++;
    while (i - p >= k) {
      c[i] = c[p];
      p++;
    }
    c[i] += t;
  }
}
int main() {
  int k1, k2, k3, t1, t2, t3;
  cin >> k1 >> k2 >> k3 >> t1 >> t2 >> t3;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    e[i] = c[i];
  }
  solve(k1, t1);
  solve(k2, t2);
  solve(k3, t3);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, c[i] - e[i]);
  cout << ans;
  return 0;
}
