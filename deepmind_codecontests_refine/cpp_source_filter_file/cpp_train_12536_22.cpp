#include <bits/stdc++.h>
using namespace std;
int n, t, dr, st, sol, a[200005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 1)
      dr++;
    else
      st++;
  }
  int x = st, y = dr, i = 1, j = n;
  a[0] = 3;
  a[n + 1] = 3;
  while (i < j) {
    while (a[i] == 0) {
      ++i;
      --x;
    }
    while (a[j] == 1) {
      --j;
      --y;
    }
    if (x < y) {
      sol += x;
      ++i;
      --y;
    } else {
      sol += y;
      --j;
      --x;
    }
  }
  cout << sol;
}
