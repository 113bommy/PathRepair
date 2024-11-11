#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, m, j, sign = 0;
  cin >> n >> m;
  for (i = n + 1;;) {
    for (j = 2; j <= (i / 2); j++) {
      if (i % j == 0) {
        sign = 1;
        break;
      }
    }
    if (sign == 1) {
      i++;
      sign = 0;
    } else {
      if (i != m)
        cout << "NO\n";
      else
        cout << "YES\n";
      return 0;
    }
  }
  return 0;
}
