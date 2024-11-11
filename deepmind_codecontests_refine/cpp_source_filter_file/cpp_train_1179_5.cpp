#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, res;
  cin >> a >> b;
  while (b) {
    res = res * 10 + b % 10;
    b /= 10;
  }
  cout << res + a;
  return 0;
}
