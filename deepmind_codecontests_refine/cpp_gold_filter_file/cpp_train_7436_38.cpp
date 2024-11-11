#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  char a[106];
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (k <= n / 2) {
    for (int i = k; i >= 2; i--) {
      cout << "LEFT" << endl;
    }
    for (int i = 1; i <= n; i++) {
      cout << "PRINT " << a[i] << endl;
      if (i != n) cout << "RIGHT" << endl;
    }
  } else {
    for (int i = k; i <= n - 1; i++) {
      cout << "RIGHT" << endl;
    }
    for (int i = n; i >= 1; i--) {
      cout << "PRINT " << a[i] << endl;
      if (i != 1) cout << "LEFT" << endl;
    }
  }
  return 0;
}
