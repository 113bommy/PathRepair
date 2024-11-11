#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 1) {
    cout << n / 2;
    return 0;
  }
  if (n == 1) {
    cout << m / 2;
    return 0;
  }
  if ((n % 2 == 0) || (m % 2 == 0))
    cout << m * n / 2;
  else
    cout << (m - 1) * n / 2 + m / 2;
  return 0;
}
