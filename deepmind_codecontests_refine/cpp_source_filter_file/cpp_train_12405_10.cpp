#include <bits/stdc++.h>
using namespace std;
const unsigned long long ha = 5123;
long long mod = 998244353;
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1},
          dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
long long qk(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return ans;
}
vector<int> vt[200005];
int fac[200005];
int in[200005];
void solve() {
  int n;
  cin >> n;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    in[x]++;
    in[y]++;
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * fac[in[i]] % mod;
  }
  cout << ans * n % mod << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  solve();
  return 0;
}
