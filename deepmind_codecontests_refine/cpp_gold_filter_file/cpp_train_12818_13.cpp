#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, c = 0;
  cin >> n >> x >> y;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (x > y) cout << n;
  if (x <= y) {
    for (int i = 0; i < n; i++)
      if (a[i] <= x) c++;
    if (c % 2 == 0)
      cout << c / 2;
    else
      cout << c / 2 + 1;
  }
  return 0;
}
