#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e6 + 500, oo = 0x3f3f3f3f;
long long ans[maxn];
void init() {
  for (int i = 1; i <= 100000; i++) {
    ans[i] = i * 1ll * i * i;
  }
}
pair<int, long long> dfs(long long t) {
  int j = lower_bound(ans + 1, ans + 100001, t) - (ans + 1);
  if (t <= 7) return pair<int, long long>(t, t);
  pair<int, long long> ans1 = dfs(t - ans[j]);
  pair<int, long long> ans2 = dfs(ans[j] - 1 - ans[j - 1]);
  if (ans1.first >= ans2.first)
    return pair<int, long long>(ans1.first + 1, ans1.second + ans[j]);
  else
    return pair<int, long long>(ans2.first + 1, ans2.second + ans[j - 1]);
}
int main(void) {
  init();
  long long m;
  scanf("%I64d", &(m));
  pair<int, long long> res = dfs(m);
  printf("%d %I64d\n", res.first, res.second);
  return 0;
}
