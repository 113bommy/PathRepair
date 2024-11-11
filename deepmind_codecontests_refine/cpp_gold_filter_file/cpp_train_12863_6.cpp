#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 1, k, k1, r;
  cin >> k >> r;
  k1 = k;
  if (k % 10 == 0)
    cout << n;
  else {
    while (k % 10 != r)
      if (k % 10 == 0) {
        break;
      } else if (k % 10 != r) {
        k += k1;
        n++;
      }
    cout << n;
  }
}
