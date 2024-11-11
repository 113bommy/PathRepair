#include <bits/stdc++.h>
using namespace std;
int prim(int a) {
  int j = 1;
  for (j = 2; j <= sqrt(a); j++) {
    if (a % j == 0) {
      break;
    }
  }
  if (j > sqrt(a - 1))
    return 1;
  else {
    return 0;
  }
}
int n, i, k1, k2, k3;
int main() {
  cin >> n;
  for (i = n; i >= 1; i--) {
    if (prim(i) == 1) {
      n -= i;
      k1 = i;
      break;
    }
  }
  if (n == 2) {
    k2 = 2;
    k3 = 0;
  }
  for (i = 2; i <= n - 2; i++) {
    if (n == 2) {
      k2 = 2;
      k3 = 0;
      break;
    } else if (n == 4) {
      k2 = 2;
      k3 = 2;
      break;
    } else if (prim(n - 2) == 1) {
      k2 = n - 2;
      k3 = 2;
      break;
    } else if (prim(i) == 1 && prim(n - i) == 1) {
      k2 = i;
      k3 = n - i;
      break;
    }
  }
  if (k2 == 0 && k3 == 0)
    cout << "1" << endl << k1;
  else if (k3 == 0)
    cout << "2" << endl << k1 << " " << k2;
  else
    cout << "3" << endl << k1 << " " << k2 << " " << k3;
}
