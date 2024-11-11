#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, ans, rep;
  cin >> a >> b >> rep;
  for (int i = 2; i <= rep; i++) {
    ans = a + b;
    a = b;
    b = ans;
  }
  cout << b << endl;
  return 0;
}
