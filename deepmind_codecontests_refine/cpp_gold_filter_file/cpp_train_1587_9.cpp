#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  v[0] = 1;
  for (long long i = 2; i < n + 1; i++) {
    if (v[i - 1]) continue;
    for (int j = i; j <= n; j += i) {
      if (v[j - 1]) continue;
      v[j - 1] = j / i;
    }
  }
  sort((v).begin(), (v).end());
  for (long long i = 1; i < n; i++) cout << v[i] << " ";
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
