#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int binp(long long int n1, long long int n2) {
  long long int re = 1;
  while (n2 > 0) {
    if (n2 % 2 == 1) {
      re = (re * n1) % mod;
    }
    n1 = (n1 * n1) % mod;
    n2 = n2 / 2;
  }
  return re;
}
int main() {
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  reverse(b.begin(), b.end());
  reverse(a.begin(), a.end());
  long long int temp = 0;
  long long int ans = 0;
  for (int i = 0; i < m; i++) {
    if (i < n && a[i] == '1') {
      temp = (temp + binp(2, i)) % mod;
    }
    if (b[i] == '1') ans += (temp) % mod;
  }
  cout << ans;
}
