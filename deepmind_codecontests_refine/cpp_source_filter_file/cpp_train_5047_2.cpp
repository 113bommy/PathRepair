#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, num = 0;
  cin >> a >> b;
  while (a != b && a && b) {
    if (a > b) {
      num += a / b;
      a %= b;
    } else {
      num += b / a;
      b %= a;
    }
  }
  cout << num;
  return 0;
}
