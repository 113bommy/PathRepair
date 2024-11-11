#include <bits/stdc++.h>
using namespace std;
int f(int x, int y, int z) {
  bool s = 0;
  if ((x < y) && (y > z)) {
    s = true;
  } else if ((x > y) && (y < z)) {
    s = true;
  }
  return s;
}
int main() {
  int n, i = 1;
  int k = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  i = 3;
  while (i <= n) {
    k = k + f(a[i - 2], a[i - 1], a[i]);
    i++;
  }
  cout << k;
}
