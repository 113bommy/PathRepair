#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
const long long MOD = (long long)1e9 + 7;
const double eps = 1e-7;
const int N = (int)1e5;
const int L = (int)1e6 + 1;
const int ALPH = 26;
struct node {
  int nxt[ALPH], link, parent, len;
  long long cost;
  node() {
    cost = 0;
    fill(nxt, nxt + ALPH, -1);
    link = -1;
    parent = -1;
    len = 0;
  }
};
int n, suff_size = 1, last_vert;
long long c[N], sum_costs[L], ans;
node suff_auto[L];
string a[N];
bool used[L];
void add(int c) {
  int v = last_vert;
  int new_v = -1;
  if (suff_auto[v].nxt[c] == -1) {
    new_v = suff_size;
    suff_auto[new_v].link = 0;
    suff_auto[new_v].parent = v;
    suff_auto[new_v].len = suff_auto[v].len + 1;
    ++suff_size;
  }
  while (v != -1) {
    if (suff_auto[v].nxt[c] == -1)
      suff_auto[v].nxt[c] = new_v;
    else {
      int q = suff_auto[v].nxt[c];
      int link_vert = q;
      if (suff_auto[q].parent != v) {
        suff_auto[suff_size].parent = v;
        for (int i = 0; i < ALPH; ++i)
          suff_auto[suff_size].nxt[i] = suff_auto[q].nxt[i];
        suff_auto[suff_size].cost = suff_auto[q].cost;
        suff_auto[suff_size].len = suff_auto[v].len + 1;
        suff_auto[suff_size].link = suff_auto[q].link;
        while (v != -1 && suff_auto[v].nxt[c] == q) {
          suff_auto[v].nxt[c] = suff_size;
          v = suff_auto[v].link;
        }
        suff_auto[q].link = suff_size;
        link_vert = suff_size;
        ++suff_size;
      }
      if (new_v != -1)
        suff_auto[new_v].link = link_vert;
      else
        new_v = link_vert;
      break;
    }
    v = suff_auto[v].link;
  }
  last_vert = new_v;
}
void dfs(int v) {
  if (used[v]) return;
  used[v] = true;
  sum_costs[v] = suff_auto[v].cost;
  for (int i = 0; i < ALPH; ++i) {
    if (suff_auto[v].nxt[i] == -1) continue;
    dfs(suff_auto[v].nxt[i]);
    sum_costs[v] += sum_costs[suff_auto[v].nxt[i]];
  }
  ans = max(ans, sum_costs[v] * suff_auto[v].len);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> c[i];
  for (int i = 0; i < n; ++i) {
    last_vert = 0;
    for (auto elem : a[i]) add(elem - 'a');
    while (last_vert != -1) {
      suff_auto[last_vert].cost += c[i];
      last_vert = suff_auto[last_vert].link;
    }
  }
  dfs(0);
  cout << ans;
  return 0;
}
