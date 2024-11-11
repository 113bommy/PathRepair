#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 3;
int ad(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int sb(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
int mu(int x, int y) { return 1ll * x * y % mod; }
int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = mu(a, a))
    if (b & 1) ans = mu(ans, a);
  return ans;
}
void fl() { fflush(stdout); }
int a[15][15];
int main() {
  for (int i = 0; i <= 10; i++) {
    cout << "? " << i << endl;
    fl();
    cin >> a[i][11];
  }
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= 10; j++) {
      a[i][j] = ksm(i, j);
    }
  }
  for (int i = 0; i <= 10; i++) {
    int iv = ksm(a[i][i], mod - 2);
    for (int j = i; j <= 11; j++) a[i][j] = mu(a[i][j], iv);
    for (int j = 0; j <= 10; j++) {
      if (i != j) {
        int ff = a[j][i];
        for (int k = i; k <= 11; k++) {
          a[j][k] = sb(a[j][k], mu(ff, a[i][k]));
        }
      }
    }
  }
  for (int i = 0; i < mod; i++) {
    int ans = 0;
    for (int j = 10; j >= 0; j--) ans = ad(mu(ans, i), a[i][11]);
    if (ans == 0) {
      cout << "! " << ans;
      fl();
      return 0;
    }
  }
  cout << "! " << 0;
  fl();
  return 0;
}
