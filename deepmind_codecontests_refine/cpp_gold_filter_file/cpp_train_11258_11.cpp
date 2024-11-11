#include <bits/stdc++.h>
using namespace std;
long long cnt[10];
long long ans = 0;
long long W;
void dfs(long long id, long long temp) {
  if (id == 9) {
    ans = max(ans, temp);
    return;
  }
  long long down = min(cnt[id], (W - temp) / id);
  long long up = 0;
  up = max((long long)0, down - 7);
  for (; up <= down; up++) {
    dfs(id + 1, temp + id * up);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> W;
  for (int i = 1; i <= 8; i++) cin >> cnt[i];
  dfs(1, 0);
  cout << ans;
}
