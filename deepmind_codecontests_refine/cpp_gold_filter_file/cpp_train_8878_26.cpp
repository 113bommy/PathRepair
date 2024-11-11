#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, k;
string s;
int main() {
  cin >> a >> b;
  string mask;
  k = b;
  while (k > 0) {
    if (k % 10 == 4 || k % 10 == 7) {
      mask += (char)('0' + k % 10);
    }
    k /= 10;
  }
  while (mask != s) {
    a++;
    s = "";
    k = a;
    while (k > 0) {
      if (k % 10 == 4 || k % 10 == 7) {
        s += (char)('0' + k % 10);
      }
      k /= 10;
    }
  }
  cout << a;
}
