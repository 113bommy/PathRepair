#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i;
  cin >> n >> m;
  i = n / 2 + (n & 1);
  i = (m >= i) ? 0 : n - 2 * m;
  cout << i << " ";
  if (!m) {
    cout << n;
    return 0;
  }
  for (i = 1; ((i * (i - 1)) / 2) < m; i++)
    ;
  cout << n - i;
  return 0;
}
