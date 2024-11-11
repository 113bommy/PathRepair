#include <bits/stdc++.h>
using namespace std;
int a[200001][19], m1[100001], m2[100001];
int m, n, k, p, b;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  while (k--) {
    cin >> p >> b;
    m1[p]++;
    m2[b]++;
  }
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) ans += m2[j];
    }
    cout << ans - m1[i] << " ";
  }
}
