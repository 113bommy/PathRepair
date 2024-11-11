#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  vector<long long> pre;
  cin >> n;
  pre.resize(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> pre[i];
  sort(pre.begin(), pre.end());
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + pre[i];
  int mid = 1, len = 0;
  long long diff = 0, sz = 1;
  for (int i = 1; i <= n; i++) {
    int l = 1, r = min(i - 1, n - i);
    while (l < r) {
      int m = (l + r + 1) >> 1;
      if ((pre[i] - pre[i - m] + pre[n] - pre[n - m + 1]) * (m + m + 1) <
          (pre[i] - pre[i - m - 1] + pre[n] - pre[n - m]) * (m + m - 1))
        l = m;
      else
        r = m - 1;
    }
    if (l == 1 &&
        (pre[i] - pre[i - l] + pre[n] - pre[n - l + 1]) * (l + l + 1) >=
            (pre[i] - pre[i - l - 1] + pre[n] - pre[n - l]) * (l + l - 1))
      l = 0;
    long long tmp_diff = pre[n] - pre[n - l] + pre[i] - pre[i - l - 1] -
                         (pre[i] - pre[i - 1]) * (l + l + 1);
    long long tmp_sz = l + l + 1;
    if (tmp_diff * sz > diff * tmp_sz) {
      diff = tmp_diff;
      sz = tmp_sz;
      mid = i;
      len = l;
    }
  }
  cout << sz << endl;
  for (int i = mid - len; i <= mid; i++) cout << pre[i] - pre[i - 1] << " ";
  for (int i = n - len + 1; i <= n; i++) cout << pre[i] - pre[i - 1] << " ";
  cout << endl;
  return 0;
}
