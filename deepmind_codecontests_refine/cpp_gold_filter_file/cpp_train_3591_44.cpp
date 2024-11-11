#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, a;
  cin >> n >> a;
  if (n == 1 && a == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (a == 1) {
    cout << 2 << endl;
    return 0;
  } else if (a == n) {
    cout << n - 1 << endl;
    return 0;
  } else {
    if (a - 1 >= n - a) {
      cout << a - 1 << endl;
    } else {
      cout << a + 1 << endl;
    }
  }
  return 0;
}
