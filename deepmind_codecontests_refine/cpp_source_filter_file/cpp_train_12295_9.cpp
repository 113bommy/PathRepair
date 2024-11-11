#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, f;
  while (cin >> a >> b) {
    if (a % b == 0) {
      cout << b / a << endl;
    } else {
      c = (int)b / a;
      cout << c + 1 << endl;
    }
  }
  return 0;
}
