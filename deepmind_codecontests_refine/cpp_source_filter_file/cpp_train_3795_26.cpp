#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, te;
  cin >> n;
  for (int i = 0; i < n; i++) {
    te = abs(n - 1 - 2 * i);
    for (int j = 1; j <= te / 2; j++) {
      cout << "* ";
    }
    for (int j = 1; j <= n - te; j++) {
      cout << "D ";
    }
    for (int j = 1; j <= te / 2; j++) {
      cout << "* ";
    }
    cout << endl;
  }
  return 0;
}
