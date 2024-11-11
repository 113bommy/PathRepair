#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, max, r = 1;
  cin >> a >> b;
  max = a ^ b;
  while (max > 0) {
    max >>= 1;
    r *= 2;
  }
  cout << r - 1 << endl;
  return 0;
}
