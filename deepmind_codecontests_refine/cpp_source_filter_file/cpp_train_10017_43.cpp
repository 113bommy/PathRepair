#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, od = 0, i, co;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 != 0) od += 1;
  }
  if (od == 0)
    co = n;
  else if (od > 0 && od % 2 == 0)
    co = n - od;
  else if (od == n)
    co = n;
  else
    co = 1;
  cout << co << endl;
  return 0;
}
