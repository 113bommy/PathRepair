#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n / 3 * 2; i++) {
      cout << 1 << " " << i << endl;
    }
    for (int i = 1; i <= n / 3; i++) {
      cout << 4 << " " << (i - 1) * 2 + 1 << endl;
    }
    for (int i = 1; i <= n % 3; i++) {
      cout << 4 << " " << (n / 3 + i - 1) * 2 + 1 << endl;
    }
  }
  return 0;
}
