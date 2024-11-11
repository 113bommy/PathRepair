#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long d, m, n = 0;
  cin >> d >> m;
  vector<long long> v;
  long long sum = 0;
  for (int i = 0; i < 32; i++) {
    long long x = binpow(2, i);
    if (sum + x <= d) {
      sum += x;
      v.push_back(x);
    } else {
      v.push_back(d - sum);
      break;
    }
  }
  n = v.size();
  if (v[v.size() - 1] == 0) {
    n--;
  }
  long long ans = v[0] % m, prev = ans;
  for (int i = 1; i < n; i++) {
    ans = v[i] + prev * v[i] % m + prev;
    ans %= m;
    prev = ans;
  }
  cout << ans % m << "\n";
}
