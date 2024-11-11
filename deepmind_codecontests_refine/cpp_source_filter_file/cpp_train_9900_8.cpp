#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, k, r, c;
  cin >> n >> k;
  if (n == 1)
    cout << 0;
  else if (k >= n) {
    r = k - n;
    if (r >= n)
      cout << 0;
    else
      cout << 1 + (n - r - 1) / 2;
  } else {
    cout << (k - 1) / 2;
  }
  return 0;
}
