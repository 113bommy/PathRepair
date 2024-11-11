#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans[100], a[100], c = 0, an = 0;
  cin >> m;
  n = m;
  while (n) {
    a[++c] = n % 2;
    n /= 2;
  }
  for (int i = c - 1; i >= 1; i--) {
    if (a[i] != a[i + 1]) ans[an++] = i;
  }
  if (m & 1)
    cout << an * 2 << endl;
  else
    cout << an * 2 - 1 << endl;
  for (int i = 0; i < an; i++) {
    cout << ans[i];
    if (i == an - 1)
      cout << endl;
    else
      cout << " ";
  }
  return 0;
}
