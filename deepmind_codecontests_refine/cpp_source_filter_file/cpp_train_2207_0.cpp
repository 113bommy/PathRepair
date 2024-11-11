#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string p = s, q = t;
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  if (p != q) {
    return -1;
  }
  int ans = INT16_MAX;
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = 0; j < n; j++)
      if (k < n && s[j] == t[k]) k++;
    ans = min(ans, n - k + i);
  }
  return ans;
}
int main() {
  int k;
  cin >> k;
  while (k > 0) {
    cout << solve();
    k--;
  }
}
