#include <bits/stdc++.h>
using namespace std;
int n, m, a[200], b[200];
int main() {
  cin >> n >> m;
  if (n == 1)
    a[1] = 1;
  else if (n == 2) {
    a[1] = 3;
    a[2] = 4;
  } else {
    a[n] = n - 2;
    for (int i = 1; i <= n - 1; i++) a[i] = 2;
  }
  if (m == 1)
    b[1] = 1;
  else if (m == 2) {
    b[1] = 3;
    b[2] = 4;
  } else {
    b[m] = m - 2;
    for (int i = 1; i <= m - 1; i++) b[i] = 2;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << a[i] * b[j] << " ";
    cout << endl;
  }
}
