#include <bits/stdc++.h>
using namespace std;
void func() {
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  int x;
  cout << a[0] << " ";
  x = a[0];
  for (int i = 2; i < n - 1; i++) {
    if (a[i] != x) {
      cout << a[i] << " ";
      x = a[i];
      continue;
    }
    if (b[i] != x) {
      cout << b[i] << " ";
      x = b[i];
      continue;
    }
    if (b[i] != x) {
      cout << c[i] << " ";
      x = c[i];
      continue;
    }
  }
  if (a[n - 1] != a[0] && a[n - 1] != x) {
    cout << a[n - 1] << endl;
    return;
  }
  if (b[n - 1] != a[0] && b[n - 1] != x) {
    cout << b[n - 1] << endl;
    return;
  }
  if (c[n - 1] != a[0] && c[n - 1] != x) {
    cout << c[n - 1] << endl;
    return;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    func();
  }
}
