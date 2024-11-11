#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> n >> m;
  if (m == 0) {
    cout << 1;
  } else if (n / 2 <= m) {
    cout << n - m;
  } else if (n / 2 > m) {
    cout << m;
  } else if (n == m) {
    cout << 0;
  }
}
