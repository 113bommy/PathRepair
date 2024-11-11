#include <bits/stdc++.h>
using namespace std;
int cntMaxSubseq(int l, int r, vector<int>& a) {
  vector<int> ss;
  for (int i = l; i < r; i++) {
    if (a[i] > a[r] || a[i] < a[l - 1]) continue;
    auto pos = upper_bound(ss.begin(), ss.end(), a[i]);
    if (pos == ss.end())
      ss.push_back(a[i]);
    else
      (*pos = a[i]);
  }
  return ss.size();
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  vector<int> b(k);
  a[0] = INT_MIN;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = INT_MAX;
  for (auto&& i : b) cin >> i;
  for (int i = 0; i < n + 2; i++) a[i] -= i;
  if (k == 0) {
    cout << cntMaxSubseq(1, n, a) << endl;
    return 0;
  } else {
    int cnt = cntMaxSubseq(1, b[0], a);
    for (int i = 0; i < k - 1; i++) {
      int l = b[i] + 1, r = b[i + 1];
      if (a[r] < a[l - 1]) {
        cout << -1 << endl;
        return 0;
      }
      cnt += cntMaxSubseq(l, r, a);
    }
    cnt += cntMaxSubseq(b[k - 1] + 1, n + 1, a);
    cout << n - cnt - b.size() << endl;
  }
  return 0;
}
