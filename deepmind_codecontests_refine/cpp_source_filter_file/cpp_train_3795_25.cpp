#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n;
  m = n / 2;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      if (j >= (m - i) && j <= (m + i))
        cout << "D";
      else
        cout << "*";
    }
    cout << "\n";
  }
  for (int i = m + 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      k = j - m;
      if (j >= (m - k) && j <= (m - k))
        cout << "D";
      else
        cout << "*";
    }
    cout << "\n";
  }
  return 0;
}
