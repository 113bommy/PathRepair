#include <bits/stdc++.h>
using namespace std;
int cor[102], wro[102];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> cor[i];
  }
  sort(cor, cor + n);
  for (int i = 0; i < m; i++) {
    cin >> wro[i];
  }
  sort(wro, wro + m);
  if (cor[0] * 2 >= wro[0] || wro[0] <= cor[n - 1]) {
    cout << -1;
  } else {
    int ans = (cor[0] * 2) > cor[n - 1] ? (cor[0] * 2) : cor[n - 1];
    cout << ans;
  }
  return 0;
}
