#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t, n, k, a, b, c, j;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    string s;
    if (n >= k) {
      a = n % k;
      b = n / k;
      for (i = 1; i <= b; i++) {
        for (j = 1; j <= k; j++) {
          s = s + (char)(96 + j);
        }
      }
      c = n - b * k;
      for (i = 1; i <= c; i++) {
        s = s + (char)(96 + i);
      }
    } else {
      for (j = 1; j <= n; j++) {
        s = s + (char)(96 + j);
      }
    }
    cout << s;
  }
  return 0;
}
