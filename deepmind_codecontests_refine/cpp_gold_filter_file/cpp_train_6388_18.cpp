#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b, long long m = 1000000007) {
  a %= m;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long bpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long modinv(long long a) { return modpow(a, 1000000007 - 2, 1000000007); }
void graph(vector<vector<long long> > &adj, long long m) {
  long long x, y;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
}
const int mxN = 2e5 + 5;
void solve() {
  int n;
  cin >> n;
  cout << max(n - 2, 0) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
