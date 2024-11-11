#include <bits/stdc++.h>
using namespace std;
int max(int a, int b, int c) {
  if (a > b && a > c) {
    return a;
  } else if (b > c) {
    return b;
  } else
    return c;
}
bool possible(int a, int b, int c, int n) {
  int sum = a + b + c + n;
  if (sum % 3 == 0) {
    int coin_per = sum / 3;
    if (max(a, b, c) < coin_per) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if (possible(a, b, c, n)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
