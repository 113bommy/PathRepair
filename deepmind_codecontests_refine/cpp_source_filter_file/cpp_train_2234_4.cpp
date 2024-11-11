#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ans = 1e9;
  for (int i = 1; i <= n / 2; ++i)
    if (((n - (i * 2)) + i) % m == 0) ans = min(ans, (n - (i * 2)) + i);
  if (ans == 1e9)
    cout << "-1";
  else
    cout << ans;
}
