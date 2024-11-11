#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  if (a - c < 0 || b - c < 0) {
    cout << "-1";
    return 0;
  }
  if (a > n || b > n || c > n || n == 0) {
    cout << "-1";
    return 0;
  }
  if (a + b - c > n - 1) {
    cout << "-1";
    return 0;
  }
  cout << n + c - a - b;
  return 0;
}
