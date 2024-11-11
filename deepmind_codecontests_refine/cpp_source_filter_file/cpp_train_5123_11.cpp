#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int n, long long int p) {
  if (p == 1) return n;
  long long int tmp = binpow(n, p / 2);
  tmp *= tmp;
  tmp %= 998244353;
  if (p % 2) tmp *= n;
  tmp %= 998244353;
  return tmp;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  long long int tmp;
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    ans = ((ans + 1ll) * (binpow(tmp, 998244353 - 2) * 100ll) % 998244353) %
          998244353;
  }
  cout << ans << '\n';
}
