#include <bits/stdc++.h>
using namespace std;
vector<int> v[300005];
pair<long long int, long long int> root[300005];
map<pair<long long int, long long int>, int> cnt;
int base1 = 127, base2 = 129, size[300005], ans, cnti, res, big[300005],
    value[300005], a[300005];
long long int mod1 = 1000000007, mod2 = 1000000007 + 2;
void pre(int cur, int par, long long int hash1, long long int hash2) {
  hash1 = (1LL * hash1 * base1 + a[cur]) % mod1;
  hash2 = (1LL * hash2 * base2 + a[cur]) % mod2;
  root[cur] = make_pair(hash1, hash2);
  size[cur] = 1;
  for (int i = 0; i < v[cur].size(); i++) {
    int x = v[cur][i];
    if (x == par) continue;
    pre(x, cur, hash1, hash2);
    size[cur] += size[x];
  }
}
void add(int cur, int par) {
  cnt[root[cur]]++;
  if (cnt[root[cur]] == 1) ans++;
  for (int i = 0; i < v[cur].size(); i++) {
    int x = v[cur][i];
    if (x == par) continue;
    add(x, cur);
  }
}
void remov(int cur, int par) {
  cnt[root[cur]]--;
  for (int i = 0; i < v[cur].size(); i++) {
    int x = v[cur][i];
    if (x == par) continue;
    remov(x, cur);
  }
}
void dfs(int cur, int par, int keep) {
  int bigchild = 0;
  for (int i = 0; i < v[cur].size(); i++) {
    int x = v[cur][i];
    if (x == par) continue;
    if (size[x] > size[bigchild]) bigchild = x;
  }
  for (int i = 0; i < v[cur].size(); i++) {
    int x = v[cur][i];
    if (x == par || x == bigchild) continue;
    dfs(x, cur, 0);
  }
  if (bigchild) {
    dfs(bigchild, cur, 1);
    big[bigchild] = 1;
  }
  for (int i = 0; i < v[cur].size(); i++) {
    int x = v[cur][i];
    if (x == par || x == bigchild) continue;
    add(x, cur);
  }
  cnt[root[cur]]++;
  if (cnt[root[cur]] == 1) ans++;
  if (ans + value[cur] > res) {
    res = ans + value[cur];
    cnti = 1;
  } else if (ans + value[cur] == res)
    cnti++;
  if (bigchild) big[bigchild] = 0;
  if (!keep) {
    cnt[root[cur]]--;
    for (int i = 0; i < v[cur].size(); i++) {
      int x = v[cur][i];
      if (x == par) continue;
      remov(x, cur);
    }
    ans = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  int i, j, n, x, y;
  string s;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> value[i];
  cin >> s;
  s = " " + s;
  for (i = 1; i <= n; i++) a[i] = s[i] - 'a';
  for (i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  pre(1, -1, 0, 0);
  dfs(1, -1, 1);
  cout << res << "\n";
  cout << cnti;
  return 0;
}
