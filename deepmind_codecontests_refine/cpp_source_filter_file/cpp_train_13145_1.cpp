#include <bits/stdc++.h>
using namespace std;
long long int mine(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int helper(long long int x, long long int plus, long long int minus) {
  if (x >= 0) return x * plus;
  return minus * (-x);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    long long int cost[6];
    for (int i = 0; i < 6; i++) cin >> cost[i];
    long long int ans = 1e18 + 1;
    ans = mine(ans, helper(x, cost[5], cost[2]) + helper(y, cost[1], cost[4]));
    ans = mine(ans,
               helper(y, cost[0], cost[3]) + helper(x - y, cost[5], cost[2]));
    ans = mine(ans,
               helper(x, cost[0], cost[3]) + helper(y - x, cost[1], cost[4]));
    cout << ans << endl;
  }
}
