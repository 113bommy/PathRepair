#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  while (k--) {
    if (n % 10)
      n = n / 10;
    else
      n = n - 1;
  }
  cout << n;
  return 0;
}
