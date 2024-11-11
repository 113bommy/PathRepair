#include <bits/stdc++.h>
using namespace std;
int mul(int a) {
  if (a < 10) return a;
  int b = 10;
  int c = a;
  while (b > 9) {
    b = 1;
    while (c != 0) {
      if (c % 10 != 0) {
        b *= (c % 10);
      }
      c /= 10;
    }
    c = b;
  }
  return b;
}
int main() {
  int q;
  cin >> q;
  int l, r, k;
  vector<vector<int>> aa(1000002, vector<int>(10, 0));
  for (int i = 1; i != aa.size(); ++i) {
    int x = mul(i);
    aa[i][x] += 1;
  }
  for (int i = 1; i != aa.size(); ++i) {
    for (int j = 1; j < 10; ++j) aa[i][j] += aa[i - 1][j];
  }
  for (int i = 0; i != q; ++i) {
    cin >> l >> r >> k;
    cout << aa[r + 1][k] - aa[l - 1][k] << "\n";
  }
  return 0;
}
