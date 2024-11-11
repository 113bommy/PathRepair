#include <bits/stdc++.h>
using namespace std;
char v[300005];
int main() {
  int n, x, y, i, zero = 0, unu = 0;
  cin >> n >> x >> y;
  for (i = 1; i <= n; i++) cin >> v[i];
  v[0] = 2;
  for (i = 1; i <= n; i++) {
    if (v[i] == '0' && v[i - 1] != '0')
      zero++;
    else if (v[i] == '1' && v[i - 1] != '1')
      unu++;
  }
  if (zero == 0)
    cout << 0;
  else
    cout << (zero - 1) * min(x, y) + y;
  return 0;
}
