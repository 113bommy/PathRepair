#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, b, n, t;
  cin >> k >> b >> n >> t;
  long long int x = 1;
  long long int y = 0;
  for (int i = 0; i <= n; i++) {
    if (x < t)
      x = k * x + b;
    else {
      cout << n - i + 1;
      y++;
      break;
    }
  }
  if (y == 0) cout << 0;
  return 0;
}
