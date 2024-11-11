#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int x, n, m, k, flag = 0;
    cin >> x >> n >> m;
    long long int sum = n + m;
    for (auto i = 0; i < sum; i++) {
      if ((x < 20 && m != 0) || n == 0) {
        x -= 10;
        m--;
      } else if ((x >= 20 && n != 0) || m == 0) {
        x = x / 2 + 10;
        n--;
      }
      if (x <= 0) {
        cout << "YES";
        break;
      }
      if (x <= 20 && m == 0) {
        cout << "N0";
        flag = 1;
        break;
      }
    }
    if (x > 0 && flag == 0) cout << "NO";
    cout << "\n";
  }
}
