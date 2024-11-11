#include <bits/stdc++.h>
using namespace std;
int in[5000], num[5000];
int get_ans(int n, int m, int k) {
  int a = n - m + 1, len = n - k, ret = 0;
  for (int i = 1; i + len - 1 <= n; i++) {
    int cnt = 0;
    for (int j = i; j <= i + len - 1; j++) num[++cnt] = in[j];
    int maxn = 1e9 + 10;
    for (int j = 1; j + a - 1 <= cnt; j++) {
      int store = max(num[j], num[j + a - 1]);
      maxn = min(maxn, store);
    }
    ret = max(maxn, ret);
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int m, n, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> in[i];
    if (k >= m - 1) {
      int len = n - m + 1, maxn = 0;
      for (int i = 1; i + len - 1 <= n; i++) {
        int store = max(in[i], in[i + len - 1]);
        maxn = max(maxn, store);
      }
      cout << maxn << endl;
    } else if (k < m - 1) {
      int ans = get_ans(n, m, k);
      cout << ans << endl;
    }
  }
  return 0;
}
