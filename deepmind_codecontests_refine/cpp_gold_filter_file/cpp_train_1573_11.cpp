#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = 0, s = 0;
  int p, k1;
  while (n) {
    p = pow(2, k);
    k1 = 2 * p - 1;
    if (k1 < n) {
      s++;
      k++;
    } else
      break;
  }
  s = s + 1;
  cout << (s);
}
