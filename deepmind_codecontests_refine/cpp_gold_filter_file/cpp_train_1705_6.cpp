#include <bits/stdc++.h>
using namespace std;
int a[33], b[33];
int main() {
  int n, m;
  cin >> n >> m;
  n = min(n, m);
  cout << n + 1 << endl;
  for (int(i) = (0); (i) < (n + 1); ++(i)) cout << n - i << " " << i << endl;
  return 0;
}
