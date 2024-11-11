#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int p = min(n, m);
  int v = n + m - 1 - p;
  cout << p << " " << v << "\n";
  return 0;
}
