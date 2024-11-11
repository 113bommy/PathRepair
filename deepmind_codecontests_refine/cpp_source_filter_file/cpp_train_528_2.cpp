#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = +3;
int t, n, m, k, ans;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    ans = 0;
    if (n < m) swap(n, m);
    if (n > k) {
      cout << -1 << endl;
      continue;
    }
    if ((n + m) % 2) {
      cout << k - 1;
    } else {
      if ((k - n) % 2) {
        cout << k - 2;
      } else {
        cout << k;
      }
    }
    cout << endl;
  }
  return 0;
}
