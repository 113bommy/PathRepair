#include <bits/stdc++.h>
using namespace std;
set<int> banx, bany;
int main() {
  int n, m, x, y;
  cin >> n >> m;
  for (int i(0); i != m; ++i) {
    cin >> x >> y;
    if (x != 1 && x != n) banx.insert(x);
    if (y != 1 && y != n) bany.insert(y);
  }
  if (n & 1) {
    int tmp(0);
    if (banx.count(n / 2 + 1) || bany.count(n / 2 + 1)) ++tmp;
    cout << (n - 1) * 2 - 3 + tmp - banx.size() - bany.size() << '\n';
  } else
    cout << n * 2 - 4 - banx.size() - bany.size() << '\n';
  return 0;
}
