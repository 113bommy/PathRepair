#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, g, b, j;
  cin >> n >> k;
  g = max(n, k);
  b = min(n, k);
  cout << g + (b - 1) << "\n";
  for (int i = 1; i <= k; i++) cout << "1 " << i << endl;
  for (int j = 2; j <= n; j++) cout << j << " 1" << endl;
  return 0;
}
