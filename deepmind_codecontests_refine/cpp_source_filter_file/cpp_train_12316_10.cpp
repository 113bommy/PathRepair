#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c, d, n, i, ans = 0;
  cin >> a >> b >> c >> d;
  for (i = 1; i <= n; ++i)
    if (i % a == 0 || i % b == 0 || i % c == 0 || i % d == 0) ++ans;
  cout << ans;
}
