#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int mod = 10007;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = (ans * 1ll + a[i] * a[n - i - 1]) % mod;
  }
  cout << ans;
  return 0;
}
