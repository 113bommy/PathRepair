#include <bits/stdc++.h>
using namespace std;
int a[7];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x] += 1;
  }
  int x = 0, y = 0, z = 0;
  int b = min({a[1], a[2], a[4]});
  x = b;
  a[1] -= b;
  a[2] -= b;
  a[4] -= b;
  b = min({a[1], a[2], a[6]});
  y = b;
  a[1] -= b;
  a[2] -= b;
  a[6] -= b;
  b = min({a[1], a[3], a[6]});
  z = b;
  a[1] -= b;
  a[3] -= b;
  a[6] -= b;
  for (int i = 1; i <= 7; i++) {
    if (a[i] != 0) {
      cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < x; i++) {
    cout << 1 << ' ' << 2 << ' ' << 4 << '\n';
  }
  for (int i = 0; i < y; i++) {
    cout << 1 << ' ' << 2 << ' ' << 6 << '\n';
  }
  for (int i = 0; i < z; i++) {
    cout << 1 << ' ' << 3 << ' ' << 6 << '\n';
  }
}
