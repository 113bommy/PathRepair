#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1007];
int b[7][1007];
int f[1007];
bool check(int x, int y) {
  for (int i = 1; i <= k; ++i) {
    if (b[i][x] < b[i][y]) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x;
      cin >> x;
      b[i][x] = j;
      if (i == 1) a[j] = x;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (check(i, j)) f[i] = max(f[i], f[j] + 1);
    }
    res = max(res, f[i]);
  }
  cout << res;
}
