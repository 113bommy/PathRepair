#include <bits/stdc++.h>
using namespace std;
int n, a[100001], ans[100001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i += 2) cin >> a[i];
  for (int i = 2; i <= n; i += 2) {
    ans[i] = 1e9;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j) continue;
      int p = j;
      int q = a[i] / p;
      if ((p + q) % 2) continue;
      int x = (q - p) / 2;
      int y = (q + p) / 2;
      if (ans[i - 2] < x) {
        if (ans[i] > y) {
          ans[i - 1] = x;
          ans[i] = y;
        }
      }
    }
    if (ans[i] == 1e9) return cout << "No" << endl, 0;
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++)
    cout << 1LL * ans[i] * ans[i] - 1LL * ans[i - 1] * ans[i - 1] << " ";
  cout << endl;
}
