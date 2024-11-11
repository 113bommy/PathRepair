#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int i = 0;
  for (i = 1; a <= b; ++i) {
    a *= 3;
    b *= 2;
  }
  cout << i - 1;
  return 0;
}
