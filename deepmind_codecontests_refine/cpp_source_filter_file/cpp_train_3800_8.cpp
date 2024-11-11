#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, x, cont = 0;
  cin >> n >> x;
  for (i = 2; i <= n; i++) {
    if (x % i == 0)
      if (x / n <= n) cont++;
  }
  cout << cont;
  return 0;
}
