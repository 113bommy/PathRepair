#include <bits/stdc++.h>
using namespace std;
int c, d, m, n, k, ans = 1000000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> c >> d;
  cin >> n >> m >> k;
  int need = n * m - k;
  for (int i = 0; i <= 5000; i++)
    for (int j = 0; j <= 5000; j++)
      if (i * n + j >= need) ans = min(ans, i * c + j * d);
  cout << ans;
}
