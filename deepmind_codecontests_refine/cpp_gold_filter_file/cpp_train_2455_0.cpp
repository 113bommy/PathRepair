#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r;
  int x[6];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  r = (n / 2.0);
  if (n > 1)
    cout << x[r];
  else
    cout << x[0];
  return 0;
}
