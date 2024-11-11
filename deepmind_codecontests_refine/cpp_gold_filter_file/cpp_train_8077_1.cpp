#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  long long i = 1;
  while (a >= 0 && b >= 0) {
    if (i % 2)
      a -= i;
    else
      b -= i;
    i++;
  }
  if (a < 0)
    cout << "Vladik" << '\n';
  else
    cout << "Valera" << '\n';
}
