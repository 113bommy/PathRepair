#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == m) {
    cout << 0;
    return 0;
  }
  if (m == 0) {
    cout << 1;
    return 0;
  }
  if (m <= n / 2) {
    cout << m;
  } else {
    cout << n - m;
  }
}
