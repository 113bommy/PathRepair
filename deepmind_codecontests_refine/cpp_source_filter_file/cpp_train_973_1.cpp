#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, v[20001], maxim, nr0, nr1, nr11, x, y, a[1001][1001], ans[200001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> x;
      if (i != j) ans[i] = ans[i] ^ x;
    }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}
