#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n < m) swap(n, m);
  cout << n - 1 << ' ' << m;
  return 0;
}
