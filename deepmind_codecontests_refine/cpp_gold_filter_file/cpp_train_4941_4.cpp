#include <bits/stdc++.h>
using namespace std;
long long n, z, rez;
int main() {
  cin >> n;
  z = 0;
  rez = 0;
  for (long long i = 1; i * 2 + z * 3 <= n; ++i) {
    if ((n - i * 2) % 3 == 0) ++rez;
    z += i;
  }
  cout << rez;
  return 0;
}
