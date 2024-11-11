#include <bits/stdc++.h>
const int mx = 1e5 + 10;
using namespace std;
pair<int, int> p[mx];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (m + i % 5) / 5;
  }
  cout << ans;
}
