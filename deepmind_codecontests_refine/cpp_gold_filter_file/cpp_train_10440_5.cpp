#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1 || m == 1) {
    cout << max(n, m) << endl;
    return 0;
  }
  if (n == 2 || m == 2) {
    n = max(n, m);
    if (n % 4 == 2) {
      cout << n + 2 << endl;
      return 0;
    }
    if (n % 2 != 0) n++;
    cout << n << endl;
    return 0;
  }
  long long ans = n * m;
  ans++;
  ans /= 2;
  cout << ans << endl;
  return 0;
}
