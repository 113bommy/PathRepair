#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 100 + 50;
vector<long long> nb[MAXN];
long long n, m, k, cmp, sz[MAXN];
bool mrk[MAXN];
long long pw(long long x, long long y) {
  if (!y) return 1;
  if (y == 1) return x % k;
  long long tmp = pw(x, y / 2);
  if (y % 2)
    return ((tmp * tmp) % k * x) % k;
  else
    return (tmp * tmp) % k;
}
void dfs(int x) {
  if (mrk[x]) return;
  mrk[x] = 1;
  sz[cmp]++;
  for (int i = 0; i < nb[x].size(); i++) dfs(nb[x][i]);
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    nb[tmp1 - 1].push_back(tmp2 - 1);
    nb[tmp2 - 1].push_back(tmp1 - 1);
  }
  for (int i = 0; i < n; i++) {
    if (!mrk[i]) {
      dfs(i);
      cmp++;
    }
  }
  if (cmp == 1) {
    cout << 1 % k << endl;
    return 0;
  }
  long long ans = pw(n, cmp - 2) % k;
  for (int i = 0; i < cmp; i++) {
    ans *= sz[i];
    ans %= k;
  }
  cout << ans << endl;
  return 0;
}
