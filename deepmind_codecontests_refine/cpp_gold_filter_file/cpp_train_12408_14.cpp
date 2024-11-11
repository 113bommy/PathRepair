#include <bits/stdc++.h>
using namespace std;
int l, r;
int d[100005];
bool ktra(int x) {
  memset(d, 0, sizeof(d));
  int dem = 0, t;
  while (x > 0) {
    int t = x % 10;
    ++d[t];
    x = x / 10;
    dem = max(dem, t);
  }
  for (int i = 0; i <= dem; ++i) {
    if (d[i] >= 2) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> l >> r;
  for (int i = l; i <= r; ++i) {
    if (ktra(i) == true) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
