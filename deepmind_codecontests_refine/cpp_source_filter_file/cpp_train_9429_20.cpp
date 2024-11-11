#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, s = 0;
  cin >> t;
  int a[t];
  for (int i = 0; i < t; i++) {
    cin >> a[i];
  }
  sort(a, a + t);
  int x, b, c;
  for (int i = 0; i < t; i++) {
    x = a[i];
    b = a[i + 1];
    c = a[i + 2];
    if (x + b > c && b + c > x && c + x > b) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
