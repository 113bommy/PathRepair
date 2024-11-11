#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[10];
  a[0] = 2;
  a[1] = 6;
  a[2] = 2;
  a[3] = 3;
  a[4] = 3;
  a[5] = 4;
  a[6] = 2;
  a[7] = 5;
  a[8] = 1;
  a[9] = 2;
  if (n % 10 == n % 100) {
    cout << a[n % 10] * 2;
  } else {
    cout << a[n % 10] * a[n / 10];
  }
  return 0;
}
