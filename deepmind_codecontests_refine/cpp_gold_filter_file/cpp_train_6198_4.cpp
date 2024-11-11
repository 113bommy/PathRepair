#include <bits/stdc++.h>
using namespace std;
int m[16], r[16];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> m[i];
  for (int i = 0; i < n; i++) cin >> r[i];
  double a = 0, b = 0;
  for (int k = 0; k < 100000; k++) {
    bool flag = false;
    for (int i = 0; i < n; i++) flag = flag | (k % m[i] == r[i]);
    if (flag) a += 1.0;
    b += 1.0;
  }
  cout.precision(6);
  cout << a / b;
  return 0;
}
