#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; 100001 > i; i++) {
    if (a < b) {
      a = a * 10;
    }
    if (a / b == c) {
      cout << i;
      return 0;
    }
    a = a % b;
  }
  cout << -1;
  return 0;
}
