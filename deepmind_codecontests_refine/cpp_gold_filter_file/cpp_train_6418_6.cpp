#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[111], b = 0, c = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0)
      b += a[i];
    else
      c += a[i];
  }
  cout << b - c << endl;
}
