#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m;
  int a[110][110], w[100];
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    int k = 0;
    for (int j = 1; j <= n; j++) {
      if (k == 0 or a[i][j] > a[i][k]) {
        k = j;
      }
    }
    w[k]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (ans == 0 or w[i] > w[ans]) {
      ans = i;
    }
  }
  cout << ans << endl;
}
