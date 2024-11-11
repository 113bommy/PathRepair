#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 5;
const long long inf = (long long)1e9 + 7;
const long long linf = (long long)1e18 + 7;
int ans = 1, x, p[N], u[N], n, f;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (!u[x]) {
      u[x] = 1;
    } else {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
