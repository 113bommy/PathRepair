#include <bits/stdc++.h>
using namespace std;
void think() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    ans += min(v[x], v[y]);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long testcase = 1;
  while (testcase--) {
    think();
  }
  return 0;
}
