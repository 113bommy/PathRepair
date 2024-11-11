#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    if (i % 3 == 1) {
      cout << i / 3 * 2 << " 0\n";
    } else if (i % 3 == 2) {
      cout << i / 3 * 2 << " 2\n";
    } else {
      cout << i / 3 * 2 << " 1\n";
    }
}
