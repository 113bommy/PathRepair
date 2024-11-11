#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, posl;
  cin >> n >> posl;
  char a[101];
  int sum = (posl - 1) + n;
  int ssum = (n - posl) + n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (sum >= ssum) {
    for (int i = posl; i < n; ++i) {
      cout << "RIGHT" << endl;
    }
    for (int i = n - 1; i >= 0; --i) {
      cout << "PRINT " << a[i] << endl;
      if (i != 0) {
        cout << "LEFT" << endl;
      }
    }
  } else if (ssum > sum) {
    for (int i = posl - 2; i >= 0; --i) {
      cout << "LEFT" << endl;
    }
    for (int i = 0; i < n; ++i) {
      cout << "PRINT " << a[i] << endl;
      if (i != n - 1) {
        cout << "RIGHT" << endl;
      }
    }
  }
  return 0;
}
