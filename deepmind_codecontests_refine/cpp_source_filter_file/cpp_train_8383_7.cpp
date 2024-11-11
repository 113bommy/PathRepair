#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, x, i, y;
  cin >> n >> k;
  if (n >= k) {
    if (n % k != 0) {
      y = n % k;
      i = k % y;
      x = n + i;
    } else {
      x = n + k;
    }
  } else {
    x = k;
  }
  cout << x << endl;
}
