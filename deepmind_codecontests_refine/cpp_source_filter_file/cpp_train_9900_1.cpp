#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  if (k <= n) {
    cout << (k - 1) / 2;
  } else if (k >= 2 * n) {
    cout << 0;
  } else {
    cout << n / 2 - (k - n) / 2;
  }
  return 0;
}
