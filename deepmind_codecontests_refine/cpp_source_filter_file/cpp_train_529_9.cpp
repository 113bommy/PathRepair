#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, l, a, s = 0, e = 0, ans = 0;
  cin >> n >> l >> a;
  for (long long int i = 0; i < n; i++) {
    long long int p, q;
    cin >> p >> q;
    q += p;
    e = p;
    ans += (e - s) / a;
    s = q + 1;
  }
  ans += (l - s) / a;
  cout << ans << "\n";
  return 0;
}
