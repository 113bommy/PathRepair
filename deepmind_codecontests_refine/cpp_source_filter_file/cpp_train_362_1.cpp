#include <bits/stdc++.h>
using namespace std;
int n, m, a[2 * 100000];
int b[11];
int main() {
  cin >> n >> m;
  bool c = false;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= 10; i++) {
    b[i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      c = true;
      break;
    }
  }
  if (c == false) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    b[a[i]]++;
  }
  for (int i = 1; i <= m; i++) {
    sum += b[i] * (n - b[i]);
  }
  cout << sum / 2;
  return 0;
}
