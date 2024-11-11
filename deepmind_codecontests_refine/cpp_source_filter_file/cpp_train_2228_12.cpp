#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, ans, ara[1001];
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> ara[i];
  }
  sort(ara, ara + m);
  ans = ara[n - 1] - ara[0];
  for (i = 1; i < m - n; i++) {
    ans = min(ans, ara[i + n - 1] - ara[i]);
  }
  cout << ans << endl;
  return 0;
}
