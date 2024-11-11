#include <bits/stdc++.h>
using namespace std;
long long tem[10000];
int cnt;
long long l, r;
long long ans;
void dfs(long long x) {
  if (x >= 10000000000LL) return;
  tem[cnt++] = x;
  dfs(x * 10 + 4);
  dfs(x * 10 + 7);
}
void make_tem() {
  cnt = 0;
  dfs(4);
  dfs(7);
  sort(tem, tem + cnt);
}
int main() {
  make_tem();
  cin >> l >> r;
  ans = 0;
  for (int i = 0; i < cnt; ++i) {
    if (tem[i] >= l) {
      ans += min(tem[i] - l + 1, r - l + 1) * tem[i];
      l = tem[i] + 1;
    }
    if (l > r) break;
  }
  cout << ans << endl;
  return 0;
}
