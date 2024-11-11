#include <bits/stdc++.h>
using namespace std;
int mod(int n) {
  if (n > 0)
    return n;
  else
    return -n;
}
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int min = mod(a[0] - a[1]);
  int x = 1;
  for (int i = 1; i < (n - 1); i++) {
    if (mod(a[i] - a[i + 1]) < min) {
      min = mod(a[i] - a[i + 1]);
      x = i + 1;
    }
  }
  if (mod(a[0] - a[n - 1]) < min)
    cout << n << " 1" << endl;
  else
    cout << x << " " << (x + 1) << endl;
  return 0;
}
