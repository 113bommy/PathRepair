#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, x;
  cin >> n >> m;
  x = m + n - 1;
  cout << x << endl;
  for (i = 1; i <= n; i++) cout << i << " " << 1 << endl;
  for (i = 2; i <= m; i++) cout << 1 << " " << i << endl;
  return 0;
}
