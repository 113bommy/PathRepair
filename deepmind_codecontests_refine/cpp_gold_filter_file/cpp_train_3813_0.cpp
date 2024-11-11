#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  }
  int ans1 = 0, ans2 = 0;
  for (int j = 0; j < m; j++) {
    int cont = 0;
    int res = 0;
    int x = 0;
    for (int i = 0; i < n; i++) {
      int aux = 0;
      for (int p = 0; p < min(k, n - i + 1); p++) {
        if (arr[p + i][j] == 1) aux++;
      }
      if (aux > res) {
        res = aux;
        x = cont;
      }
      if (arr[i][j] == 1) cont++;
    }
    ans1 += res;
    ans2 += x;
  }
  cout << ans1 << " " << ans2 << '\n';
  return 0;
}
