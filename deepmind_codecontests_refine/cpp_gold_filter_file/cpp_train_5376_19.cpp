#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int m, n, r = 1;
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    r = r * 2;
    if (r > m) {
      cout << m << endl;
      break;
    }
    if (i == n) {
      cout << (m % r) << endl;
    }
  }
  return 0;
}
