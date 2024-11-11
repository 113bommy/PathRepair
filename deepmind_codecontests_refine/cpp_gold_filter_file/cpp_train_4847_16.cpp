#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n;
  cin >> n;
  long long int k = 1;
  if (n == 1) {
    cout << 1;
    return 0;
  } else if (n == 0) {
    cout << 1;
    return 0;
  } else
    for (i = 1; i < n; i++) {
      k = (3 * k) % (1000000 + 3);
    }
  cout << k;
  return 0;
}
