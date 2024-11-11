#include <bits/stdc++.h>
using namespace std;
void OJ() {}
int solve() {
  long long int n, l, a;
  cin >> n >> l >> a;
  long long int q = 0, t = 0;
  while (n--) {
    long long int m, c;
    cin >> m >> c;
    if ((m - t) >= a) q += (m - t) / a;
    t += (m - t) % a;
    t += c;
  }
  q += (l - t) / a;
  cout << q;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  solve(), cout << endl;
  return 0;
}
