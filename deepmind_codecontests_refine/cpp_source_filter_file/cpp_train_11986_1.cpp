#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int dp[100005];
bool lgl[100005];
int lst[100005];
vector<int> jl[100005];
vector<int> ans[100005];
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  memset(lgl, 0, sizeof(lgl));
  int rem = n;
  int grp = 0;
  while (rem) {
    memset(dp, 0x3f, sizeof(dp));
    int mxpos = 0;
    for (int i = 1; i <= n; i++) {
      if (!lgl[a[i]]) {
        int pos = lower_bound(dp + 1, dp + n + 1, a[i]) - dp;
        mxpos = max(mxpos, pos);
        dp[pos] = a[i];
        lst[i] = dp[pos - 1];
      }
    }
    if (mxpos * (mxpos + 1) / 2 <= rem) {
      for (int i = 1; i <= n; i++) {
        jl[i].clear();
      }
      memset(dp, 0x3f, sizeof(dp));
      mxpos = 0;
      for (int i = 1; i <= n; i++) {
        if (!lgl[a[i]]) {
          int pos = lower_bound(dp + 1, dp + n + 1, a[i]) - dp;
          mxpos = max(mxpos, pos);
          dp[pos] = a[i];
          jl[pos].push_back(a[i]);
          rem--;
        }
      }
      for (int i = 1; i <= mxpos; i++) {
        if (jl[i].size()) {
          ans[++grp] = jl[i];
        }
      }
    } else {
      int x = dp[mxpos];
      ans[++grp].clear();
      while (x != 0x3f3f3f3f) {
        ans[grp].push_back(x);
        lgl[x] = 1;
        x = lst[x];
        rem--;
      }
      reverse(ans[grp].begin(), ans[grp].end());
    }
  }
  printf("%d\n", grp);
  for (int i = 1; i <= grp; i++) {
    printf("%d", (int)ans[i].size());
    for (int j = 0; j < ans[i].size(); j++) {
      printf(" %d", ans[i][j], j == ans[i].size() - 1 ? '\n' : ' ');
    }
    puts("");
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
