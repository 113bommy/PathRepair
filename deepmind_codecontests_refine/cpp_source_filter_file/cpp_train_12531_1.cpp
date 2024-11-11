#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    m = 0;
    while ((a > 0) && (b > 0)) {
      if (b > a) {
        a = a + b;
        b = a - b;
        a = a - b;
      }
      m += a / b;
      a = a % b;
    }
    cout << m;
  }
  return 0;
}
