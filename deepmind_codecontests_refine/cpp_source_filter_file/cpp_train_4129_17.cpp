#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, a, b, x = 3;
  cin >> n >> m >> a >> b;
  if ((a - 1) / m == b / m) {
    cout << 1;
    return 0;
  }
  if ((a - 1) % m == 0) {
    x--;
  }
  if (b % m == 0 || b == n) {
    x--;
  }
  if (x == 3 && ((a - 1) / m) == (b / m) - 1) {
    x--;
  }
  if (x == 3 && (m - a + 1 + b) % m == 0) {
    x--;
  }
  cout << x;
  return 0;
}
