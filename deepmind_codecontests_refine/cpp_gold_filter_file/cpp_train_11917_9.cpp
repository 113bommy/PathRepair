#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  if (n == 1)
    cout << 1;
  else {
    for (i = 1; i <= n; i++) {
      n -= (i * (i + 1)) / 2;
      if (n < 0) break;
    }
    cout << i - 1;
  }
  return 0;
}
