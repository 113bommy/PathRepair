#include <bits/stdc++.h>
using namespace std;
void f();
int main() {
  int t;
  cin >> t;
  while (t--) {
    f();
  }
  return 0;
}
void f() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max((a + b), (c + d)) << endl;
}
