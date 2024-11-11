#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, f;
  while (cin >> a >> b) {
    if (b % a == 0) {
      cout << b / a << endl;
    } else {
      c = b / a;
      cout << c + 1 << endl;
    }
  }
  return 0;
}
