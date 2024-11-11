#include <bits/stdc++.h>
using namespace std;
unsigned long long int mod = 998244353;
unsigned long long int e(unsigned long long int a, unsigned long long int b,
                         unsigned long long int c) {
  if (b == 0) {
    return 1;
  }
  unsigned long long int aa = 1;
  if (b % 2 == 1) {
    aa = a;
  }
  unsigned long long int ans = e(a, b / 2, c);
  return (((ans * ans) % mod) * aa) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long int n;
  unsigned long long int m;
  unsigned long long int aa;
  cin >> n;
  vector<unsigned long long int> it[n];
  map<unsigned long long int, unsigned long long int> ss;
  for (unsigned long long int i = 0; i < n; i++) {
    cin >> m;
    for (unsigned long long int j = 0; j < m; j++) {
      cin >> aa;
      it[i].push_back(aa);
      if (ss.find(aa) == ss.end()) {
        ss[aa] = 1;
      } else {
        ss[aa] += 1;
      }
    }
  }
  unsigned long long int ans = 0;
  for (unsigned long long int i = 0; i < n; i++) {
    unsigned long long int d = it[i].size();
    for (unsigned long long int j = 0; j < d; j++) {
      ans += ss[it[i][j]] * e(d, mod - 2, mod);
      ans %= mod;
    }
  }
  cout << ((ans * e((n * n), mod - 2, mod)) % mod) << endl;
}
