#include <bits/stdc++.h>
using namespace std;
int n, d[10005];
int mo(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  cout.flush();
  int c;
  cin >> c;
  return c;
}
int main() {
  cin >> n;
  int mx = 1;
  for (int i = 2; i <= n; i++) {
    int a = mo(mx, i), b = mo(i, mx);
    if (a > b) {
      d[mx] = a;
      mx = i;
    } else
      d[i] = b;
  }
  d[mx] = n;
  cout << "! ";
  cout.flush();
  for (int i = 1; i <= n; i++) {
    cout << d[i] << ' ';
    cout.flush();
  }
  return 0;
}
