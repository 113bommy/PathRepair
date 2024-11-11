#include <bits/stdc++.h>
using namespace std;
void file() {}
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
int main() {
  fast();
  int n, m, r, arr1[10000], arr2[10000], s = 0, mn = 100000, mx = -1;
  cin >> n >> m >> r;
  int x = r, z;
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
    if (arr1[i] < mn) mn = arr1[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> arr2[i];
    if (arr2[i] > mx) mx = arr2[i];
  }
  while (r >= mn) {
    r -= mn;
    s++;
  }
  z = r + (s * mx);
  cout << max(z, x);
}
