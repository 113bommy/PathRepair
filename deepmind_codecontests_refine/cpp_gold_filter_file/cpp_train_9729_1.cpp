#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, b = 0;
  cin >> n >> m;
  b = n;
  while (n / m != 0) {
    b += n / m;
    n = n / m + n % m;
  }
  cout << b << endl;
  return 0;
}
