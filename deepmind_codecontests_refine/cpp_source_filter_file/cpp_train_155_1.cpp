#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (n == 4 && k < n) {
    cout << -1;
    return;
  }
  if (n > 4 && k < n + 1) {
    cout << -1;
    return;
  }
  cout << a << " " << c << " ";
  for (long long i = 1; i < 1 + n; i++) {
    if (i != a && i != b && i != c && i != d) cout << i << " ";
  }
  cout << d << " " << b << endl;
  cout << c << " " << a << " ";
  for (long long i = 1; i < 1 + n; i++) {
    if (i != a && i != b && i != c && i != d) cout << i << " ";
  }
  cout << b << " " << d;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
