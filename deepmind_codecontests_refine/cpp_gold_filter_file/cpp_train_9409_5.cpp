#include <bits/stdc++.h>
using namespace std;
long long n, arr[(int)(510)][(int)(510)], ans[(int)(510)], a[(int)(510)];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> arr[i][j];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int q = n; q >= 1; q--) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        arr[i][j] = min(arr[i][j], arr[i][a[q]] + arr[a[q]][j]);
    for (int i = q; i <= n; i++)
      for (int j = q; j <= n; j++) ans[q] += arr[a[i]][a[j]];
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
