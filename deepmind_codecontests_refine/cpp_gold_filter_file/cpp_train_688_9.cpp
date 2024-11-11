#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int f[n + 2];
  f[0] = 1;
  f[1] = 1;
  for (i = 2; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }
  int t = 1;
  for (i = 1; i <= n; i++) {
    if (i == f[t]) {
      cout << "O";
      t++;
    } else
      cout << "o";
  }
  return 0;
}
