#include <bits/stdc++.h>
using namespace std;
int N = 1000000007;
void solve() {
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  vector<int> v;
  for (int i = 2; i < n; i++) {
    while (n % i == 0 && cnt < k - 1 && n > 2) {
      v.push_back(i);
      n /= i;
      cnt++;
    }
  }
  if (cnt < k - 1) {
    cout << -1;
    return;
  }
  for (auto it : v) cout << it << " ";
  cout << n;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
