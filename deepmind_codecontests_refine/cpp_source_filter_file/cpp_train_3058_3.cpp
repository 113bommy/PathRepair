#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  a *= 10;
  for (int i = 0; i < 9; i++) {
    if ((a + i) % b == 0) {
      string s(n - 1, '0');
      cout << a + i << s;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
