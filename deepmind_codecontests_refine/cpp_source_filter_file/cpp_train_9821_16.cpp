#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n;
  cin >> a >> b >> n;
  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  cout << c;
  return 0;
}
