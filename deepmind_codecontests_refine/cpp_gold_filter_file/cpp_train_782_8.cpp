#include <bits/stdc++.h>
using namespace std;
const int mod = 1E9 + 7;
const int maxn = 100000;
const int inf = 0x3f3f3f;
long long jpow(long long x) { return x * x * x; }
pair<long long, long long> ans;
void dfs(long long m, long long num, long long x) {
  if (m == 0) {
    ans = max(ans, make_pair(num, x));
    return;
  }
  long long tmp = 1;
  while (jpow(tmp + 1) <= m) tmp++;
  dfs(m - jpow(tmp), num + 1, x + jpow(tmp));
  if (tmp >= 1) dfs(jpow(tmp) - 1 - jpow(tmp - 1), num + 1, x + jpow(tmp - 1));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long m;
  cin >> m;
  dfs(m, 0, 0);
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
