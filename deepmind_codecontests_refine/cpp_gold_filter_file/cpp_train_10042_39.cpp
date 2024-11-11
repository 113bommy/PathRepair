#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if ((i * (i + 1)) / 2 == n) {
      cout << "YES" << endl;
      return 0;
    }
    if ((i * (i + 1)) / 2 > n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  return 0;
}
