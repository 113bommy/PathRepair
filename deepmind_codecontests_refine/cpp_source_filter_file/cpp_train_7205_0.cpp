#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, n;
    cin >> a >> b >> c >> n;
    long long mx =
        ((a) > (((b) > (c) ? (b) : (c))) ? (a) : (((b) > (c) ? (b) : (c))));
    n -= ((mx - a) + (mx - b) + (mx - c));
    if (n > 0 && n % 3 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
