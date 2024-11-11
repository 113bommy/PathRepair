#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int premax[maxn], suffmin[maxn], a[maxn];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    premax[0] = a[0];
    for (int i = 1; i < n; i++) premax[i] = max(premax[i - 1], a[i]);
    suffmin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) suffmin[i] = min(suffmin[i + 1], a[i]);
    int ans = 1;
    for (int i = 0; i < n - 1; i++)
      if (premax[i] <= suffmin[i + 1]) ans++;
    cout << ans << endl;
  }
}
