#include <bits/stdc++.h>
using namespace std;
int a[100001];
int func(int n) {
  if (n == 0)
    return 2;
  else if (n == 1)
    return 7;
  else if (n == 2)
    return 2;
  else if (n == 3)
    return 3;
  else if (n == 4)
    return 3;
  else if (n == 5)
    return 4;
  else if (n == 6)
    return 2;
  else if (n == 7)
    return 5;
  else if (n == 8)
    return 1;
  else if (n == 9)
    return 2;
}
int main() {
  int i, j, k, l, t, m, n;
  cin >> n;
  if (n < 10) {
    m = 0;
    n = n;
  } else {
    m = n / 10;
    n = n % 10;
  }
  int p = func(m);
  int q = func(n);
  cout << p * q << endl;
  return 0;
}
