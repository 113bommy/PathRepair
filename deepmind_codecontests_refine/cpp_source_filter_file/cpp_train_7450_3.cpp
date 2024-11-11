#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long int k;
  cin >> n >> k;
  if (k % 2) {
    cout << 1;
    return 0;
  } else if (k == (1 << n - 1)) {
    cout << n;
    return 0;
  } else {
    for (int i = 2; i <= n; i++) {
      if (k % (1 << i) == (1 << i - 1)) {
        cout << i;
        return 0;
      }
    }
  }
  return 0;
}
