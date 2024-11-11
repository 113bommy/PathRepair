#include <bits/stdc++.h>
using namespace std;
int n, m, a[105][105], mn = 9999999, mnn[105];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    mn = 999999;
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (mn > a[i][j]) {
        mn = a[i][j];
        mnn[i] = a[i][j];
      }
    }
  }
  int mx = -99999;
  for (int i = 1; i <= n; i++) {
    if (mnn[i] > mx) mx = mnn[i];
  }
  cout << mx;
}
