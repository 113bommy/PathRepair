#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 1 && n == 1) {
    cout << 1 << "\n";
  } else if (m > double(n) / 2) {
    cout << m - 1 << "\n";
  } else {
    cout << m + 1 << "\n";
  }
  return 0;
}
