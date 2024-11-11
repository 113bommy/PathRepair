#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[m];
  for (int s = 0; s < m; s++) a[s] = 1e6;
  int cnt = 0;
  int l = 0;
  while (n--) {
    l++;
    int i, j;
    cin >> i >> j;
    a[i - 1] = min(a[i - 1], j);
  }
  while (m--) {
    cnt = cnt + a[m];
  }
  cout << cnt;
  return 0;
}
