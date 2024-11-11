#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
  cin >> a;
  while (a > 0) {
    b++;
    d = c + b;
    c = d;
    a = a - d;
    if (a < 0) {
      b--;
    }
    cout << b;
  }
}
