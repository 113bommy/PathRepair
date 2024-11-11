#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
};
int main() {
  int t = 1;
  while (t--) {
    long long int n, k, query, u, v;
    cin >> n >> k >> query;
    vector<long long int> q;
    long long int a[n];
    for (int i = (0); i < (n); i++) cin >> a[i];
    for (int i = (0); i < (query); i++) {
      string ans = "NO";
      cin >> u >> v;
      if (u == 1) {
        if (q.size() == k) {
          sort(q.begin(), q.end(), greater<int>());
          if (a[v] > q[k - 1]) {
            q.pop_back();
            q.push_back(a[v - 1]);
          }
          sort(q.begin(), q.end(), greater<int>());
        } else {
          q.push_back(a[v - 1]);
        }
      } else {
        for (int i = (0); i < (q.size()); i++) {
          if (a[v - 1] == q[i]) ans = "YES";
        }
        cout << ans << endl;
      }
    }
  }
  return 0;
}
