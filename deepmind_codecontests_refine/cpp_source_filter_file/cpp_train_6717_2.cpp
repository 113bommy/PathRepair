#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 1;
  cin >> n;
  if (n > 1) {
    for (int i = 1; i <= n + 1; i++) {
      m = m * 2;
    }
    m = m - 2;
  } else {
    m = 2;
  }
  cout << m;
  return 0;
}
