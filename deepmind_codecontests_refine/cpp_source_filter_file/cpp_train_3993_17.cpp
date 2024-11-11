#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a;
  cin >> n >> m >> a;
  n = (n - 1) / a + 1;
  m = (m - 1) / a + 1;
  cout << n * m << endl;
  return 0;
}
