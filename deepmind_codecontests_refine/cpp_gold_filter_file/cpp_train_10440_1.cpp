#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1 || m == 1) {
    cout << max(n, m);
    return 0;
  }
  int a = min(n, m), b = max(n, m), c = !(b % 4);
  if (a == 2)
    cout << 2 * ((b + 2) / 2 - c);
  else
    cout << (n * m + 1) / 2;
  return 0;
}
