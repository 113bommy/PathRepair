#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  if (m == 0) {
    cout << 1;
    return 0;
  }
  if (m == n) {
    cout << 0;
    return 0;
  }
  int x = cnt = n / 2;
  if (x == m) {
    cout << x;
    return 0;
  }
  if (x < m) {
    m -= x;
    cout << x - m + n % 2;
    return 0;
  }
  cout << m;
  return 0;
}
