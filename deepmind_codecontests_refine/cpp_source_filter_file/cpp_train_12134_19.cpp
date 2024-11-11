#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int maxl = 0;
  int s = 0;
  int tol;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a[n] = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > a[i + 1]) {
      tol = i + 1 - s;
      if (tol > maxl) {
        maxl = tol;
      }
      s = i + 1;
    }
  }
  cout << maxl;
  return 0;
}
