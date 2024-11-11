#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, years;
  cin >> a >> b;
  while (a <= b) {
    a *= 3;
    b *= 2;
    years++;
  }
  cout << years;
  return 0;
}
