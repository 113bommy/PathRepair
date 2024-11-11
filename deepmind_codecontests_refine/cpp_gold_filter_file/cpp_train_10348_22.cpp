#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000 * 50 + 4, Inf = 1e9 + 10;
int main() {
  int n, m;
  cin >> m >> n;
  cout << n + m - 1 << endl;
  for (int i = 1; i <= m; i++) cout << i << " " << 1 << endl;
  for (int j = 2; j <= n; j++) cout << 1 << " " << j << endl;
  return 0;
}
