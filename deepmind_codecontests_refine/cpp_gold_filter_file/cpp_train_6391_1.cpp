#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5 + 8;
int const delta = 1000000007;
int cnt1[MAXN];
int cnt2[MAXN];
int ans[MAXN];
int st[MAXN];
int sz;
int main() {
  int n, m;
  cin >> n >> m;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    cnt1[t]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> t;
    cnt2[t]++;
  }
  for (int i = 0, j = 0; j < 2 * m; i++, j++, i %= m) {
    while (cnt2[i]) {
      cnt2[i]--;
      st[sz++] = i;
    }
    while (sz && cnt1[m - 1 - i]) {
      cnt1[m - 1 - i]--;
      sz--;
      ans[(m - 1 - i + st[sz]) % m]++;
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < ans[i]; j++) cout << i << " ";
  }
  return 0;
}
