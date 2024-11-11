#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n, m;
    cin >> n >> m;
    if (n == 1) {
      cout << m << endl;
      continue;
    }
    if (n == 2) {
      cout << m << endl;
      continue;
    }
    cout << 2 * m << endl;
  }
  return 0;
}
