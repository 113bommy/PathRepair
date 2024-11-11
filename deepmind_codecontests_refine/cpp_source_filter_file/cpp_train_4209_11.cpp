#include <bits/stdc++.h>
using namespace std;
int n, k, a[105], frecv[5];
int main() {
  int ans = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) {
    frecv[1] = 0;
    frecv[2] = 0;
    for (int j = 1; j <= k; j++) frecv[a[(j - 1) * k + i]]++;
    if (frecv[1] && frecv[2]) ans += min(frecv[1], frecv[2]);
  }
  cout << ans;
  return 0;
}
