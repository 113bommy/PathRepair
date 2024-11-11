#include <bits/stdc++.h>
using namespace std;
int n, m, nr;
int af;
int main() {
  cin >> n >> m >> nr;
  m += 2;
  n += 2;
  for (int i = 1; i <= nr; i++) {
    n -= 2;
    m -= 2;
    af += (2 * m + 2 * n - 4);
  }
  cout << af << '\n';
  return 0;
}
