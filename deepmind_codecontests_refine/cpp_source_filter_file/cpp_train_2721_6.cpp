#include <bits/stdc++.h>
using namespace std;
int main() {
  double n;
  int d, dd, cp = 0, co = 0, cn = 0, m;
  cin >> n;
  double a[105];
  dd = ceil(n / 2);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0)
      cp++;
    else if (a[i] < 0)
      cn++;
    else
      co++;
  }
  if (cp > co && cp > cn && cp >= dd)
    d = dd;
  else if (cn > cp && cn > co && cn >= dd)
    d = dd * -1;
  else
    d = 0;
  cout << d << endl;
  return 0;
}
