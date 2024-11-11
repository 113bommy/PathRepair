#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n, m; cin >> n >> m;
  if (n > m) swap(n, m);
  for (int i = 0; i < m; ++i) cout << n;
  return 0;
}