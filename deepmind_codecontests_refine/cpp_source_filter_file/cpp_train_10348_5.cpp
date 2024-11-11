#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  cout << n + m - 1 << endl;
  for (int j = 1; j <= m; j++) {
    cout << 1 << '\t' << j << endl;
  }
  for (int i = 1; i <= n; i++) {
    cout << i << '\t' << 2 << endl;
  }
  return 0;
}
