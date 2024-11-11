#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
int n, d[1000111], a[1000111];
long long res = 0;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; cin >> a[i]; i++) d[a[i]] = i;
  for (int i = 2; i <= n; i++) res += d[i] - d[i - 1];
  cout << res;
}
