#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == m) {
    cout << "0";
  } else if (m == 0) {
    cout << "1";
  } else if (n >= 2 * m) {
    cout << m;
  } else {
    cout << n - m;
  }
  return 0;
}
