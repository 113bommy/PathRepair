#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> vc;
  for (int i = (1); i <= (n); ++i) {
    int x;
    scanf("%d", &x);
    vc.push_back(x);
  }
  vector<int> vt;
  vt.push_back(-1000000007);
  for (int i = (1); i <= (m); ++i) {
    int x;
    scanf("%d", &x);
    vt.push_back(x);
  }
  vt.push_back(1000000007);
  int ans = 0;
  for (int i = (0); i <= (n - 1); ++i) {
    int k = lower_bound(vt.begin(), vt.end(), vc[i]) - vt.begin();
    int left = 1000000007;
    int right = 1000000007;
    if (k > 1) left = vc[i] - vt[k - 1];
    if (k <= m) right = vt[k] - vc[i];
    ans = max(ans, min(left, right));
  }
  printf("%d", ans);
  return 0;
}
