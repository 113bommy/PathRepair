#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, o = 0, e = 0, x, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0)
      e++;
    else
      o++;
  }
  if (o % 2 == 1)
    cout << o;
  else
    cout << e;
  return 0;
}
