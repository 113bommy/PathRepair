#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, i, k;
  cin >> n >> k;
  x = 240 - k;
  for (i = 1; x - 5 * i >= 0 && i <= n; i++) {
    x = x - 5 * i;
  }
  cout << --i;
}
