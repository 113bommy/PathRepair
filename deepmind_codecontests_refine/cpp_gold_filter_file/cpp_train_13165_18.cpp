#include <bits/stdc++.h>
int a[20], n;
using namespace std;
int main() {
  a[0] = 2;
  a[1] = 7;
  a[2] = 2;
  a[3] = 3;
  a[4] = 3;
  a[5] = 4;
  a[6] = 2;
  a[7] = 5;
  a[8] = 1;
  a[9] = 2;
  cin >> n;
  cout << a[n % 10] * a[n / 10];
  return 0;
}
