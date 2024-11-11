#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> as(n);
  for (int i = 0; i < n; i++) cin >> as[i];
  sort(as.rbegin(), as.rend());
  long long ans = 0;
  ans += 1ll * as[0] * (m % (k + 1));
  ans += (1ll * as[0] * k + as[1]) * (m / (k + 1));
  cout << ans << endl;
}
