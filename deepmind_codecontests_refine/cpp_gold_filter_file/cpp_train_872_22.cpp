#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 74, M = 1e6 + 74, OO = 0x3f3f3f3f;
const double EPS = 1e-9;
long long arr[4][N][N];
int n;
void add(int i, int jj, long long v) {
  int c = (i & 1) | ((jj & 1) << 1);
  while (i <= n) {
    int j = jj;
    while (j <= n) {
      arr[c][i][j] ^= v;
      j += (j & -j);
    }
    i += (i & -i);
  }
}
long long get(int i, int jj) {
  long long v = 0;
  int c = (i & 1) | ((jj & 1) << 1);
  while (i) {
    int j = jj;
    while (j) {
      v ^= arr[c][i][j];
      j ^= (j & -j);
    }
    i ^= (i & -i);
  }
  return v;
}
long long get2d(int b, int l, int t, int r) {
  long long v = 0;
  v ^= get(t, r);
  v ^= get(t, l - 1);
  v ^= get(b - 1, r);
  v ^= get(b - 1, l - 1);
  return v;
}
void add2d(int x0, int y0, int x1, int y1, int v) {
  add(x0, y0, v);
  add(x0, y1 + 1, v);
  add(x1 + 1, y0, v);
  add(x1 + 1, y1 + 1, v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(NULL);
  int m;
  cin >> n >> m;
  while (m--) {
    int t;
    cin >> t;
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    if (x0 > x1) swap(x0, x1);
    if (y0 > y1) swap(y0, y1);
    if (t == 1) {
      long long res = 0;
      res = get2d(x0, y0, x1, y1);
      cout << res << '\n';
    } else {
      long long v;
      cin >> v;
      add2d(x0, y0, x1, y1, v);
    }
  }
  return 0;
}
