#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  if (n == 1) {
    cout << 0 << endl;
    cout << 0 << endl;
    cout << 0 << endl;
    return 0;
  }
  if (n == 2) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    a[i] = i;
    cout << a[i] << " ";
  }
  cout << "" << endl;
  int b[n], c[n];
  for (int i = 0; i < n; i++) {
    b[i] = (i + 1) % n;
    cout << b[i] << " ";
  }
  cout << "" << endl;
  for (int i = 0; i < n; i++) {
    cout << (a[i] + b[i]) % n << " ";
  }
  cout << "" << endl;
  return 0;
}
