#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long binpow(long long a, long long b) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void input() { cin >> n >> m; }
void solve() {
  long long ans = binpow(3, n);
  ans--;
  if (ans <= 0) ans += m;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  long long t = 1;
  while (t--) {
    input();
    solve();
    cout << endl;
  }
  cin.get();
  return 0;
}
