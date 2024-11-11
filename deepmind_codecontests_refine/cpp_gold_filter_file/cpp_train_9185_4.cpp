#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int t, n, k;
int a[200005];
int cnt[400010];
int b[400010];
int c[400010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i <= 2 * k + 5; ++i) {
      cnt[i] = b[i] = c[i] = 0;
    }
    for (int i = 1; 2 * i <= n; ++i) {
      ++cnt[a[i] + a[n - i + 1]];
      ++b[max(a[i], a[n - i + 1]) + k + 1];
      ++c[min(a[i], a[n - i + 1])];
    }
    for (int i = 2 * k; i > 0; --i) {
      c[i] += c[i + 1];
    }
    for (int i = 1; i <= 2 * k; ++i) {
      b[i] += b[i - 1];
    }
    int res = n - 1;
    for (int i = 1; i <= 2 * k; ++i) {
      res = min(res, (n >> 1) - cnt[i] + b[i] + c[i]);
    }
    cout << res << endl;
  }
  return 0;
}
