#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
int n, a, b, c, d;
vector<int> g[5050];
int par[5050];
int cnt[5050];
vector<int> v;
int gettype(int x) {
  int last = -1;
  while (x != 0) {
    last = x;
    x = par[x];
  }
  return last;
}
void dfs(int v) {
  cnt[v] = ((int)g[v].size() == 0);
  for (__typeof(g[v].begin()) it = g[v].begin(); it != g[v].end(); it++) {
    dfs(*it);
    cnt[v] += cnt[*it];
  }
}
void print(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
vector<int> get_all_submask(vector<int> &values) {
  const int MAX_SIZE = 5050 * 2;
  bitset<MAX_SIZE> dp;
  dp[0] = 1;
  for (__typeof(values.begin()) it = values.begin(); it != values.end(); it++) {
    int value = *it;
    dp |= (dp << value);
  }
  vector<int> ans;
  for (int i = 0; i < MAX_SIZE; i++) {
    if (dp[i]) ans.push_back(i);
  }
  return ans;
}
vector<int> get(int local_root, int leaf) {
  int leaf_degree = 0;
  int x = leaf;
  vector<int> values;
  while (x != 0) {
    int y = par[x];
    leaf_degree++;
    if (y != 0) {
      for (__typeof(g[y].begin()) it = g[y].begin(); it != g[y].end(); it++) {
        int to = *it;
        if (to != x) values.push_back(cnt[to]);
      }
    }
    x = y;
  }
  vector<int> ans = get_all_submask(values);
  for (int i = 0; i < ans.size(); i++) {
    ans[i] += 1;
  }
  return ans;
}
vector<int> get_diff(vector<int> &a, vector<int> &b) {
  int mx = 5050 * 2;
  const int MAX_SZ = 5050 * 2 * 2 + 100;
  bitset<MAX_SZ> dp;
  for (int i = 0; i < a.size(); i++) {
    dp[a[i]] = 1;
  }
  bitset<MAX_SZ> ans;
  for (int i = 0; i < b.size(); i++) {
    ans |= (dp << (mx - b[i]));
  }
  vector<int> values;
  for (int i = 0; i < MAX_SZ; i++) {
    if (ans[i]) values.push_back(i - mx);
  }
  return values;
}
bool solve(int a, int b, int c, int d) {
  int ta = gettype(a);
  int tb = gettype(b);
  int tc = gettype(c);
  int td = gettype(d);
  v.clear();
  for (__typeof(g[0].begin()) it = g[0].begin(); it != g[0].end(); it++) {
    int x = *it;
    if (x != ta && x != tb && x != tc && x != td) v.push_back(cnt[x]);
  }
  vector<int> va = get(ta, a);
  vector<int> vb = get(tb, b);
  vector<int> vc = get(tc, c);
  vector<int> vd = get(td, d);
  int sa = cnt[ta];
  int sb = cnt[tb];
  int sc = cnt[tc];
  int sd = cnt[td];
  int m = cnt[0];
  vector<int> diff_ab = get_diff(vb, va);
  vector<int> diff_cd = get_diff(vd, vc);
  vector<int> values = get_all_submask(v);
  vector<int> is_value(2 * n, 0);
  for (__typeof(values.begin()) it = values.begin(); it != values.end(); it++)
    is_value[*it] = 1;
  for (__typeof(diff_ab.begin()) it = diff_ab.begin(); it != diff_ab.end();
       it++) {
    for (__typeof(diff_cd.begin()) it1 = diff_cd.begin(); it1 != diff_cd.end();
         it1++) {
      int x = *it;
      int y = *it1;
      x = m / 2 - 1 - sa - sc - x;
      y = m / 2 - 1 - sc - sb - y;
      if (x >= 0 && x < 2 * n && y >= 0 && y < 2 * n) {
        if (is_value[x] && is_value[y]) return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  a--;
  b--;
  c--;
  d--;
  for (int i = 1; i < n; i++) {
    int x;
    scanf("%d", &x);
    x--;
    g[x].push_back(i);
    par[i] = x;
  }
  par[0] = -1;
  dfs(0);
  if (cnt[0] % 2)
    printf("NO\n");
  else if (solve(a, b, c, d) || solve(a, b, d, c))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
