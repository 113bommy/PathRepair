#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n >> m;
  cout << n + m - 1 << endl;
  for (i = 1; i <= m; i++) cout << 1 << " " << i << endl;
  for (i = 2; i <= n; i++) cout << 2 << " " << i << endl;
}
