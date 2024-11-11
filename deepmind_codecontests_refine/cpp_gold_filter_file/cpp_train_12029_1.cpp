#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  bool b = 0;
  cin >> n;
  for (int i = 0; 1234567 * i <= n && !b; i++) {
    m = n - (i * 1234567);
    for (int j = 0; 123456 * j <= m; j++) {
      k = m - (j * 123456);
      if (k % 1234 == 0) {
        b = 1;
        break;
      }
    }
  }
  if (b)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
