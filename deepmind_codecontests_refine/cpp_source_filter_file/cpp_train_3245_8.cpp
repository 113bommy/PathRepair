#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[a]++;
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    if (v[i] % 2) ans++;
  }
  cout << n - ans / 2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
