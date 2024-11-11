#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 1) {
    if (n == 1)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  } else if (m == n) {
    cout << n - 1 << "\n";
  } else {
    int a = m - 1;
    int b = n - m;
    if (a > b) {
      cout << m - 1 << "\n";
    } else if (b > a) {
      cout << m + 1 << "\n";
    }
    if (b == a) cout << m << "\n";
  }
  return 0;
}
