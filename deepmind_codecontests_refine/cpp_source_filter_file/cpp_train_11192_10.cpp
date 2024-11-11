#include <bits/stdc++.h>
using namespace std;
const int LMAX = 200002;
int n, m, a[LMAX], b[LMAX];
int binarySearch(int x, int s, int d) {
  if (s > d) return d;
  int mij = (s + d) / 2;
  if (a[mij] <= x)
    return binarySearch(x, mij + 1, d);
  else
    return binarySearch(x, s, mij - 1);
}
int binary_search(int x) {
  int st = 0, dr = m + 1;
  while (dr - st > 1) {
    int mij = (st + dr) / 2;
    if (a[mij] > x) {
      dr = mij;
    } else
      st = mij;
  }
  return dr - 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    cout << binary_search(b[i]) << " ";
  }
}
