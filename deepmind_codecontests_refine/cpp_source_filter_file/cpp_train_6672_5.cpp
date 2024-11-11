#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, a, b, asc = 100000000, flag1 = 1;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (flag1 == 0) continue;
    if (max(a, b) <= asc) {
      asc = max(a, b);
    } else if (min(a, b) <= asc) {
      asc = min(a, b);
    } else
      flag1 = 0;
  }
  if (flag1 == 0)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
