#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int m, n, a, b;
  bool result = false;
  cin >> m >> n;
  a = m;
  b = m / 2;
  if (m % 2 != 0) b++;
  for (long long int i = b; i <= a; i++) {
    if (i % n == 0) {
      cout << i << endl;
      result = true;
      break;
    }
  }
  if (!result) cout << -1 << endl;
}
