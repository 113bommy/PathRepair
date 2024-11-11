#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  cout << n + m - 1 << endl;
  for (int i = 1; i <= m; i++) cout << "1 " << m << endl;
  for (int i = 2; i <= n; i++) cout << i << " 1" << endl;
  return 0;
}
