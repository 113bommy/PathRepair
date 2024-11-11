#include <bits/stdc++.h>
using namespace std;
long long n, i, z;
int main() {
  cin >> n;
  z = 1;
  for (i = 1; i <= 150; i++) {
    z += (i + 2) * (i + 1) / 2;
    if (n < z) {
      break;
    }
  }
  cout << i << endl;
  return 0;
}
