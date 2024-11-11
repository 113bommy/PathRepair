#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  while (tc--) {
    long long n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    vector<long long> a(n), b(m), v(1, -1);
    for (long long i = 0; i < (n); i++) cin >> a[i];
    for (long long i = 0; i < (m); i++) cin >> b[i];
    if (m > n) {
      cout << -1 << "\n";
      continue;
    }
    bool flag = 0;
    for (long long i = 0, j = 0; i < m; i++, j++) {
      while (j < n && a[j] != b[i]) {
        j++;
      }
      if (j == n) {
        flag = 1;
        break;
      }
      v.push_back(j);
    }
    if (flag) {
      cout << -1 << "\n";
      continue;
    }
    v.push_back(n);
    long long ans = 0;
    if (x <= y * k) flag = 1;
    for (long long i = 0; i < (v.size() - 1); i++) {
      long long len = v[i + 1] - v[i] - 1;
      long long segmi = max((i > 0 ? a[v[i]] : a[v[i + 1]]),
                            (i < v.size() - 2 ? a[v[i + 1]] : a[v[i]])),
                segm = segmi;
      for (long long j = v[i] + 1; j < v[i + 1]; j++) {
        segm = max(segm, a[j]);
      }
      if (segm > segmi && len < k) {
        ans = -1;
        break;
      } else if (segm > segmi) {
        if (flag)
          ans += (len / k) * x + (len % k) * y;
        else
          ans += x + ((len - k) % k) * y;
      } else {
        if (flag)
          ans += (len / k) * x + (len % k) * y;
        else
          ans += len * y;
      }
    }
    cout << ans << "\n";
  }
  cerr << "Time : " << ((double)clock()) / (double)CLOCKS_PER_SEC << "s\n";
  return 0;
}
