#include <bits/stdc++.h>
using namespace std;
long long w, ans = 0, cnt[9];
void dfs(int now, long long sum) {
  ans = max(ans, sum);
  if (now < 1) return;
  long long mx = min((w - sum) / now, cnt[now]);
  long long mi = max((long long)0, mx - 2);
  for (long long i = mi; i <= mx; i++) {
    dfs(now - 1, sum + now * i);
  }
}
int main() {
  cin >> w;
  for (int i = 1; i < 9; i++) cin >> cnt[i];
  dfs(8, 0);
  cout << ans;
  return 0;
}
