#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n % 2 == 0) {
    if (m <= n / 2) {
      cout << 2 * m - 1;
    } else
      cout << (m - n / 2) * 2;
  } else {
    if (m <= n / 2 + 1) {
      cout << 2 * m - 1;
    } else
      cout << (m - (n / 2 + 1)) * 2;
  }
}
