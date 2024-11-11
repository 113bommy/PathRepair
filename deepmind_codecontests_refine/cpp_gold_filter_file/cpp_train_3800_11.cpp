#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, x, cont = 0;
  cin >> n >> x;
  for (i = 1; i <= n; i++) {
    if (x % i == 0)
      if (x / i <= n) cont++;
  }
  cout << cont;
  return 0;
}
