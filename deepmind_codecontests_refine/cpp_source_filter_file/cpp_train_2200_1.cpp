#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5, M = 20 + 2;
long long adj[M], bad[1 << M][2];
bool b[1 << M][2];
int bst[1 << M];
int n, m;
bool mark[MAXN];
string s[MAXN];
int c[MAXN];
set<int> ksh[MAXN];
map<string, int> mp;
set<string> st;
void input();
void base();
void solve();
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  input();
  base();
  solve();
  return 0;
}
void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    if (c[i] - 1) {
      cin >> s[i];
      st.insert(s[i]);
    }
    if (c[i] == 2 && c[i - 1] == 1) mark[i] = true;
  }
}
void base() {
  int j = 0;
  for (auto i : st) mp[i] = j++;
  for (int i = 0, j = 0; i < n; i++)
    if (c[i] - 1) {
      if (mark[i]) j = i;
      int cp = mp[s[i]];
      for (auto v : ksh[j]) {
        adj[cp] |= (1ll << v);
        adj[v] |= (1ll << cp);
      }
      ksh[j].insert(cp);
    }
  for (int i = 0; i < m; i++)
    if (adj[i] & (1ll << i)) adj[i] -= (1ll << i);
}
void solve() {
  int mid = m / 2;
  b[0][0] = b[0][1] = true;
  for (int i = 0; i < 1 << mid; i++)
    if (b[i][0]) {
      bst[i] = __builtin_popcount(i);
      for (int j = 0; j < mid; j++)
        if (~(i | bad[i][0]) & (1 << j)) {
          b[i + (1 << j)][0] = true;
          bad[i + (1 << j)][0] = bad[i][0] | adj[j];
        }
    }
  for (int i = 0; i < 1 << mid; i++)
    for (int j = 0; j < mid; j++)
      bst[i | (1 << j)] = max(bst[i | (1 << j)], bst[i]);
  int x = (1 << mid) - 1, ans = bst[x];
  for (int i = 0; i < 1 << (m - mid); i++)
    if (b[i][1]) {
      ans = max(ans, __builtin_popcount(i) + bst[x - (x & bad[i][1])]);
      for (int j = mid; j < m; j++)
        if (~bad[i][1] & (1 << j)) {
          b[i | (1 << (j - mid))][1] = true;
          bad[i | (1 << (j - mid))][1] = bad[i][1] | adj[j];
        }
    }
  cout << ans << endl;
}
