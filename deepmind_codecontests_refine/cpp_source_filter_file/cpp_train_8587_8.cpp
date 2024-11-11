#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = 1000, i, j, k;
  cout << n << "\n";
  for (i = 1; i <= n; i++) cout << i << " 1 " << i << " 2\n";
  for (i = n; i >= 1; i--) cout << i << " 1 " << i << " 2\n";
  return 0;
}
