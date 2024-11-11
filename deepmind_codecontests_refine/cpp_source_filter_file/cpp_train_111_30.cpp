#include <bits/stdc++.h>
using namespace std;
int a[105];
signed main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int k = 0; k <= 200; k++) {
    bool ok = 1;
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] > k) {
        ok = 0;
        break;
      }
      tmp += k - a[i];
    }
    if (tmp <= sum || ok == 0)
      continue;
    else {
      cout << k;
      return 0;
    }
  }
}
