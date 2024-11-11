#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i * 1234567 > n) break;
    for (int j = 1; j <= n; j++) {
      long long d;
      d = n - ((i * 1234567) + (j * 123456));
      if (d < 0) break;
      if (d % 1234 == 0 && d > 0) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
