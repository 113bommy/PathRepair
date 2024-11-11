#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, a, b, c, d, ans, ans1, ans2;
  cin >> n;
  vector<long long> v(2 * n);
  for (i = 0; i < 2 * n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  ans = 1000000001;
  for (i = 1; i <= n - 1; i++) {
    if (ans >= (v[i + n - 1] - v[i])) ans = v[i + n - 1] - v[i];
  }
  ans1 = ans * (v[(2 * n) - 1] - v[0]);
  ans2 = (v[n - 1] - v[0]) * (v[(2 * n) - 1] - v[n]);
  ans = min(ans1, ans2);
  cout << ans << endl;
}
