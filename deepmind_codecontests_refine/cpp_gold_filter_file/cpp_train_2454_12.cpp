#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  while (!(a * 2 <= b && a * 4 <= c)) {
    --a;
    if (a == 0) break;
  }
  cout << a * 7;
  return 0;
}
