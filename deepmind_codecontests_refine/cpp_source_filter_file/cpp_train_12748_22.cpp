#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  for (i = 0, j = 1; i < n - 1; i++) {
    j = (j + i + 1) % n;
    if (j != 0)
      cout << j << ' ';
    else
      cout << 1 << ' ';
  }
  return 0;
}
