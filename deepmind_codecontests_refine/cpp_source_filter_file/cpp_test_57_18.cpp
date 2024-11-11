#include <bits/stdc++.h>
using namespace std;
long long s, n, k;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> s >> n >> k;
    if (k > s)
      cout << "NO\n";
    else if (k == s)
      cout << "YES\n";
    else {
      long long a1 = (s + k + 1) / k, a2 = (s + k + 1) % k, tot = s + k + 1;
      if (s / k % 2 == 0) {
        tot -= a2;
      } else {
        tot -= k - a2;
      }
      if (tot < 2 * n + 2)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
