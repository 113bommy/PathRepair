#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int v = min(n, m);
  int p = n + m - 1 - v;
  cout << p << " " << v << "\n";
  return 0;
}
