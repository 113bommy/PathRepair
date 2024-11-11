#include <bits/stdc++.h>
using namespace std;
void solve() {
  long int n, k, a, i, c = 0, s = 0, d = 1, c1 = 0;
  cin >> n >> k;
  long int ar[n];
  a = (n - k);
  for (i = 0; i < n; i++) {
    cin >> ar[i];
    if (ar[i] > a) {
      c++;
      d = ((d % 998244353) * (c % 998244353)) % 998244353;
      c = 0;
      s += ar[i];
      c1++;
    } else if (s > 0 && c1 < k) {
      c++;
    }
  }
  cout << s << " " << (d % 998244353);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
