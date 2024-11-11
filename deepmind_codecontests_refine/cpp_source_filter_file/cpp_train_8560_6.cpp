#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, n, m;
    cin >> x >> n >> m;
    if (m * 10 >= x) {
      cout << "YES" << endl;
      continue;
    }
    long long int s = x;
    while (n > 0) {
      s = (s / 2) + 10;
      n--;
    }
    while (m > 0) {
      s = s - 10;
      if (s == 0) break;
      m--;
    }
    if (s == 0) cout << "YES" << endl;
    if (s != 0) cout << "NO" << endl;
  }
}
