#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  int arr[m + 1];
  for (int i = 0; i <= m; i++) cin >> arr[i];
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x = arr[m] ^ arr[i];
    int c = 0;
    while (x) {
      c += x % 2;
      x /= 2;
    }
    if (c <= k) ans++;
  }
  cout << ans;
}
