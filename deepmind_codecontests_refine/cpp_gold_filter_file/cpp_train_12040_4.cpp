#include <bits/stdc++.h>
using namespace std;
int used[1000001];
int a[1000001][10];
int rq(int n) {
  int p = 1;
  while (n > 0) {
    if (n % 10 != 0) {
      p *= (n % 10);
    }
    n /= 10;
  }
  if (used[p] != 0) return used[p];
  if (p >= 10)
    rq(p);
  else
    return p;
}
int main() {
  int q;
  cin >> q;
  for (int i = 1; i <= 1e6; i++) {
    int res = rq(i);
    for (int j = 1; j <= 9; j++) {
      if (j == res)
        a[i][j] = a[i - 1][j] + 1;
      else
        a[i][j] = a[i - 1][j];
    }
  }
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << a[r][k] - a[l - 1][k] << endl;
  }
}
