#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n, m;
  int cnt = 0, sum = 0, res = 0;
  cin >> n >> m;
  if (n <= m * 2) {
    cout << n;
    return 0;
  }
  if (m <= n * 2) {
    cout << m;
    return 0;
  } else {
    cout << (n + m) / 3;
  }
  return 0;
}
