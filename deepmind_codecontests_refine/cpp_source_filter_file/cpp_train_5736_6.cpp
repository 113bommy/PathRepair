#include <bits/stdc++.h>
using namespace std;
int n, m, sum, c;
unordered_map<int, int> mp;
long long ans;
int main() {
  cin >> n >> m;
  mp[1] = 1;
  bool can = 0;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c < m)
      sum++;
    else if (c > m)
      sum--;
    if (c == m) can = 1;
    if (can) {
      ans += mp[sum] + mp[sum - 1];
    } else {
      mp[sum]++;
    }
  }
  cout << ans;
}
