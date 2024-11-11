#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> h;
long long int fact(long long int n) {
  if (h.count(n)) return n;
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) {
    ans = ans * i;
    ans %= 1000000007;
  }
  return h[n] = ans;
}
long long int xpow(long long int a, long long int p) {
  if (p == 0) return 1;
  long long int aa = xpow(a, p / 2);
  aa *= aa;
  aa %= 1000000007;
  if (p & 1) {
    aa *= a;
    aa %= 1000000007;
  }
  return aa;
}
void solve() {
  long long int n;
  cin >> n;
  cout << (fact(2 * n) * xpow(2, 1000000007 - 2) % 1000000007) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
