#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 9, mod1 = 1e9 + 9;
long long c[300005], idd[300005], po[300005], po1[300005], m;
vector<long long> ed[300005];
set<pair<long long, long long> > my[300005];
pair<long long, long long> has[300005];
string s;
long long base = 10000007;
long long merge(long long x, long long y) {
  if (my[x].size() < my[y].size()) swap(x, y);
  for (auto el : my[y]) my[x].insert(el);
  return x;
}
long long ans = -1, cn = 0;
long long dfs(int in, int par, pair<long long, long long> ha, int p) {
  ha = make_pair((ha.first + s[in] * po[p] % mod) % mod,
                 (ha.second + s[in] * po1[p] % mod1) % mod1);
  long long id = m++;
  my[id].insert(ha);
  for (auto x : ed[in]) {
    if (x == par) continue;
    long long id1 = dfs(x, in, ha, p + 1);
    id = merge(id, id1);
  }
  idd[in] = id;
  long long tmp = my[id].size() + c[in];
  if (tmp > ans) {
    ans = tmp;
    cn = 1;
  } else if (tmp == ans)
    cn++;
  return id;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  po[0] = 1;
  for (long long i = 1; i <= (300005 - 1); i++) po[i] = po[i - 1] * base % mod;
  po1[0] = 1;
  for (long long i = 1; i <= (300005 - 1); i++)
    po1[i] = po1[i - 1] * base % mod1;
  long long n;
  cin >> n;
  for (long long i = 0; i < (n); i++) cin >> c[i];
  cin >> s;
  for (long long i = 0; i < (n - 1); i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ed[x].push_back(y), ed[y].push_back(x);
  }
  dfs(0, -1, make_pair(0, 0), 0);
  cout << ans << endl << cn;
  return 0;
}
