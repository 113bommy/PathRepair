#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> pos, neg;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x == 0) continue;
    if (x > 0)
      pos.push_back(x);
    else
      neg.push_back(x);
  }
  sort(pos.begin(), pos.end());
  sort(neg.rbegin(), neg.rend());
  int64_t ans = 0, mx = 0;
  for (int len = pos.size(), i = len - 1; i >= 0; i -= k) {
    ans += 2 * pos[i];
    mx = max(mx, pos[i]);
  }
  for (int len = neg.size(), i = len - 1; i >= 0; i -= k) {
    ans += -2 * neg[i];
    mx = max(mx, -neg[i]);
  }
  cout << ans - mx << '\n';
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int Case = 1;
  cin >> Case;
  for (int i = 1; i <= Case; i++) {
    test_case();
  }
  return 0;
}
