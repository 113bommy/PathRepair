#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  if (n == 1) {
    cout << m / 6 * 3 + max(m % 6 - 3, 0ll) / 2;
  } else if (n == 2) {
    if (m == 2) {
      cout << 0;
    } else if (m == 3) {
      cout << 4;
    } else if (m == 7) {
      cout << 12;
    } else {
      cout << m / 2;
    }
  } else {
    cout << n * m - (n * m) % 2;
  }
  cout << '\n';
  return 0;
}
