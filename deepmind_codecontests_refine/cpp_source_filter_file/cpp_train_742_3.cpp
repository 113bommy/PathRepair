#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<long long, int> > a(n);
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].first *= (i + 1) * (n - i);
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  long long ans = 0, mod = 998244353;
  for (int i = 0; i < n; i++) {
    ans += (a[i].first % mod * b[i]) % mod;
    ans %= mod;
  }
  cout << ans;
}
