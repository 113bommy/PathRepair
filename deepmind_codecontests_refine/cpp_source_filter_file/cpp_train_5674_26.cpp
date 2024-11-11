#include <bits/stdc++.h>
using namespace std;
int n, m, mx;
int arr[105][105], frq[105];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    mx = 0;
    int ind = -1;
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] > mx) ind = j;
      mx = max(mx, arr[i][j]);
    }
    frq[ind]++;
  }
  int ans = -1, mx = 0;
  for (int i = 1; i <= n; i++) {
    if (frq[i] > mx) ans = i;
    mx = max(frq[i], mx);
  }
  cout << ans << endl;
}
