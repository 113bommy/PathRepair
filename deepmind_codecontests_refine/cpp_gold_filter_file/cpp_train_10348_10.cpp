#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> n >> m;
  cout << m + n - 1 << endl;
  for (int i = 1; i <= m; i++) cout << "1 " << i << endl;
  for (int i = 2; i <= n; i++) cout << i << " " << m << endl;
  return 0;
}
