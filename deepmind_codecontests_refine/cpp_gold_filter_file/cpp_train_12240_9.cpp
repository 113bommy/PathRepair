#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int c = 2 * m;
  cout << (k + c - 1) / c << ' ' << ((k - 1) % c + 2) / 2 << ' '
       << (k % 2 ? "L" : "R") << endl;
  return 0;
}
