#include <bits/stdc++.h>
using namespace std;
long long n1, n2, k1, k2, i, j;
int main() {
  cin >> n1 >> n2 >> k1 >> k2;
  for (i = 0;; i++) {
    n1--;
    if (n1 < 0) {
      cout << "second";
      return 0;
    }
    n2--;
    if (n2 < 0) {
      cout << "first";
      return 0;
    }
  }
  return 0;
}
