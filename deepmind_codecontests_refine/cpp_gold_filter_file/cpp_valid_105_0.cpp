#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int T, n;
int a[maxn], dp[maxn][maxn], pos[maxn];
vector<int> vec[maxn];
int calc(int l, int r) {
  if (l > r) return 0;
  int &ret = dp[l][r];
  if (ret >= 0) return ret;
  ret = calc(l, r - 1);
  for (int i = pos[r] - 1; i >= 0; i--) {
    int p = vec[a[r]][i];
    if (p < l) break;
    ret = max(ret, calc(l, p) + calc(p + 1, r - 1) + 1);
  }
  return ret;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) vec[i].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      pos[i] = int(vec[a[i]].size());
      vec[a[i]].push_back(i);
    }
    for (int l = 1; l <= n; l++)
      for (int r = l; r <= n; r++) dp[l][r] = -1;
    printf("%d\n", n - calc(1, n) - 1);
  }
  return 0;
}
