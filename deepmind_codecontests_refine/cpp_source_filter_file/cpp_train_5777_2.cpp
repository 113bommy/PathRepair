#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    cout << "1";
    return 0;
  }
  if (n < 4) {
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i += 2) {
      cout << i << " ";
    }
  } else if (n == 4) {
    cout << "4\n";
    cout << "1 4 2 3\n";
  } else {
    cout << n << "\n";
    for (int i = 1; i <= n; i += 2) {
      cout << i << " ";
    }
    for (int i = 2; i <= n; i += 2) {
      cout << i << " ";
    }
  }
  return 0;
}
