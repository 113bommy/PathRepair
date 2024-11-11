#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[100006] = {0};
  cout << "1 ";
  int var = 1;
  a[1] = 1;
  a[0] = 1;
  while (k) {
    if (var - k > 1 && a[var - k] == 0) {
      cout << var - k << " ";
      a[var - k] = 1;
      var = var - k;
    }
    if (a[var + k] == 0 && var + k <= n) {
      cout << var + k << " ";
      a[var + k] = 1;
      var = var + k;
    }
    k--;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      cout << i << " ";
    }
  }
  return 0;
}
