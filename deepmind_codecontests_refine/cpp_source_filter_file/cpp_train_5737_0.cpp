#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> l, r, prl, prr, sul, sur;
int main() {
  cin >> n;
  l.assign(n, 0), r.assign(n, 0);
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  prl.assign(n + 1, 0), prr.assign(n + 1, 0);
  sul.assign(n + 1, 0), sur.assign(n + 1, 0);
  prl[0] = sul[n] = 0;
  prr[0] = sur[n] = 0xffffff;
  for (int i = 0; i < n; i++) {
    prl[i + 1] = max(prl[i], l[i]);
    prr[i + 1] = min(prr[i], r[i]);
  }
  for (int i = n - 1; i >= 0; --i) {
    sul[i] = max(sul[i + 1], l[i]);
    sur[i] = min(sur[i + 1], r[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, min(prr[i], sur[i + 1]) - max(prl[i], sul[i + 1]));
  cout << ans;
  return 0;
}
