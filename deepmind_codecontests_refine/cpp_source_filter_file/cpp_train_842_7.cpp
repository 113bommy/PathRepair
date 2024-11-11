#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n / 4 * 3; i++) {
      cout << 1 << " " << i << endl;
    }
    for (int i = 1; i <= n / 4; i++) {
      cout << 4 << " " << (i - 1) * 3 + 1 << endl;
    }
    for (int i = 1; i <= n % 4; i++) {
      cout << 4 << " " << (n / 4 + i - 1) * 3 + 1 << endl;
    }
  }
  return 0;
}
