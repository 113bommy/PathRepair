#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 1 << endl;
  } else if (m == n) {
    cout << 0 << endl;
  } else if (n / 2 <= m) {
    cout << n - m << endl;
  } else {
    cout << m << endl;
  }
  return 0;
}
