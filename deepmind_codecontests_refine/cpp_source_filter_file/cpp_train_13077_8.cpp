#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int a, b;
  cin >> a >> b;
  if (b - a >= 10)
    cout << 0;
  else {
    int p = a % 10;
    int q = b % 10;
    int r = 1;
    if (p >= q)
      cout << 0;
    else {
      for (int i = p + 1; i <= q; i++) {
        r = (r * i) % 10;
      }
      cout << r;
    }
  }
  return 0;
}
