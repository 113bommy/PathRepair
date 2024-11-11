#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, count, n, k;
  cin >> k;
  char c = '1';
  n = k * 2;
  char a[4][4];
  for (i = 0; i < 4; ++i)
    for (j = 0; j < 4; ++j) cin >> a[i][j];
  while (c <= 9) {
    count = 0;
    for (i = 0; i < 4; ++i) {
      for (j = 0; j < 4; ++j) {
        if (a[i][j] == c) ++count;
      }
    }
    ++c;
    if (count > n) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
