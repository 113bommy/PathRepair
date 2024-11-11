#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int power(long long int x, long long int y) {
  if (y == 0) return 1;
  if (y == 1) return x % 10;
  long long int r = power(x, y >> 1);
  return (((r * r) % 10) * power(x, y & 1)) % 10;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int ans = 0;
  vector<long long int> v(m);
  multiset<long long int> st;
  for (long long int i = 0; i < m; i++) {
    cin >> v[i];
    st.insert((v[i]));
    for (auto j : st)
      if (j < v[i]) ans++;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
