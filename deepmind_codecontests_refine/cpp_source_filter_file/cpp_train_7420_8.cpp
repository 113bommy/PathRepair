#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n < m) swap(n, m);
  if (m == 1)
    cout << 1 << endl;
  else if (m == 2) {
    cout << 2 * (2 * (n / 4) + min(n % 4, 2)) << endl;
  } else {
    cout << n * m - (n * m) / 2 << endl;
  }
}
