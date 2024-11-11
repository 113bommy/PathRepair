#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, val = 0;
  cin >> n;
  for (int i = 3; i <= n; i++) {
    if (i == 3) {
      val = 1 * 2 * 3;
    } else {
      val = val + (i * (i - 1));
    }
  }
  cout << val;
  return 0;
}
