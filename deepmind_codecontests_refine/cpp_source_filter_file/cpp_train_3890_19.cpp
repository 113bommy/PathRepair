#include <bits/stdc++.h>
using namespace std;
unsigned long long int power(unsigned long long int n,
                             unsigned long long int m) {
  if (n == 0LL)
    return 1 % m;
  else if (n & 1LL)
    return ((power(n / 2, m) % m) * (power(n / 2, m) % m) * (3 % m)) % m;
  else
    return ((power(n / 2, m) % m) * (power(n / 2, m) % m)) % m;
}
void solve() {
  unsigned long long int n, m, ans;
  cin >> n >> m;
  ans = ((power(n, m) % m) - 1) % m;
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  unsigned long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
