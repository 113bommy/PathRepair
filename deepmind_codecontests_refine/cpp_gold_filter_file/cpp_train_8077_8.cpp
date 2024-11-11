#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i = 1, j = 1;
  cin >> n >> m;
  while (1) {
    if (j % 2 == 1) {
      if ((n - i) >= 0) {
        n = n - i;
      } else {
        cout << "Vladik";
        return 0;
      }
    } else {
      if ((m - i) >= 0) {
        m = m - i;
      } else {
        cout << "Valera";
        return 0;
      }
    }
    j++;
    i++;
  }
  return 0;
}
