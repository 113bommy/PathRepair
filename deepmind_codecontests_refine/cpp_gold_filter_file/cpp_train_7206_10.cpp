#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  string s[101], p;
  cin >> t;
  while (t--) {
    long long int n, m, l, k, d, j, h, f;
    cin >> n >> m >> l >> k;
    if (n == 1)
      cout << max(n * (m - k - 1), (n * k)) << endl;
    else if (m == 1)
      cout << max(m * (n - l - 1), (m * l)) << endl;
    else {
      j = max(n * (m - k - 1), (n * k));
      h = max(m * (n - l - 1), (m * l));
      cout << max(j, h) << endl;
    }
  }
  return 0;
}
