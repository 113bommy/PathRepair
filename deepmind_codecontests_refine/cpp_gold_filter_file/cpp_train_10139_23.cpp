#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[m];
  if (n % m == 0) {
    for (int i = 0; i < m; i++) {
      a[i] = n / m;
      cout << a[i] << " ";
    }
  } else {
    for (int i = 0; i < m; i++) {
      a[i] = n / m;
    }
    for (int i = m - (n % m); i < m - (n % m) + n % m; i++) {
      a[i] += 1;
    }
    for (int i = 0; i < m; i++) cout << a[i] << " ";
  }
  return 0;
}
