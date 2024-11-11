#include <bits/stdc++.h>
using namespace std;
int qaq(int a, int b) {
  if (a % b == 0) {
    return a / b;
  }
  return a / b + (b, a % b);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      a += b;
      b = a - b;
      a -= b;
    }
    cout << qaq(a, b) << endl;
  }
  return 0;
}
