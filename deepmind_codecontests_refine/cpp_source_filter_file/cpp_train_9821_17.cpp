#include <bits/stdc++.h>
using namespace std;
int a[40], f;
int main() {
  cin >> a[0] >> a[1] >> f;
  for (int i = 3; i <= f; i++) a[i] = a[i - 1] + a[i - 2];
  cout << a[f] << endl;
  return 0;
}
