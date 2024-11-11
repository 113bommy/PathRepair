#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int e(long long int a, long long int b, long long int c) {
  if (b == 0) {
    return 1;
  }
  long long int aa = 1;
  if (b % 2 == 1) {
    aa = a;
  }
  long long int ans = e(a, b / 2, c);
  return (((ans * ans) % mod) * aa) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  long long int m;
  long long int aa;
  cin >> n;
  vector<long long int> it[n];
  map<long long int, long long int> ss;
  for (long long int i = 0; i < n; i++) {
    cin >> m;
    for (long long int j = 0; j < m; j++) {
      cin >> aa;
      it[i].push_back(aa);
      if (ss.find(aa) == ss.end()) {
        ss[aa] = 1;
      } else {
        ss[aa] += 1;
      }
    }
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int d = it[i].size();
    for (long long int j = 0; j < d; j++) {
      ans += ss[it[i][j]] * e(d, mod - 2, mod);
      ans %= mod;
    }
  }
  cout << ((ans * e(n * n, mod - 2, mod)) % mod) << endl;
}
