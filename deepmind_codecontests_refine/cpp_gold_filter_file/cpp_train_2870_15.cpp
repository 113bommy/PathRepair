#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int MAXI = 2000000000;
int ans = MAXI;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  pair<int, int> r;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> r.first >> r.second;
    int temp = r.second - r.first + 1;
    ans = min(temp, ans);
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    cout << i % ans << " ";
  }
  return 0;
}
