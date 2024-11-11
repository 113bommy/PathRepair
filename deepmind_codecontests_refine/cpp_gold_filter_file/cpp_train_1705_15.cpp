#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int x = min(n, m) + 1;
  cout << x << "\n";
  for (int i = 0; i < x; ++i) cout << i << " " << x - i - 1 << "\n";
  return 0;
}
