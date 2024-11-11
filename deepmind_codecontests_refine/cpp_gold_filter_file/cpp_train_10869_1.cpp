#include <bits/stdc++.h>
using namespace std;
int absolute(int a, int b) {
  if (a > b)
    return (a - b);
  else
    return (b - a);
}
int main() {
  int n, i, j, k;
  cin >> n;
  int a[100];
  cin >> a[0];
  int maks = 10000;
  int l = 0;
  for (i = 1; i < n; i++) {
    cin >> a[i];
    if (maks > absolute(a[i], a[i - 1])) {
      maks = absolute(a[i], a[i - 1]);
      l = i;
    }
  }
  if (maks > absolute(a[n - 1], a[0])) {
    l = n;
  }
  cout << l << "  " << (l % n) + 1;
}
