#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10, MS = 1e6 + 10, MN = 15;
int rl[MN], rr[MN], ver[MN];
string rule[MN];
int n;
vector<int> topol, rev[MS];
int dp[11][MS], beg[11][MS];
map<char, int> nxt[MS];
bool mk[MN];
int lst, sz = 1, link[MS], len[MS];
void add(char c) {
  int p = lst;
  lst = sz++;
  for (; !nxt[p].count(c); p = link[p]) nxt[p][c] = lst;
  int q = nxt[p][c];
  if (q == lst) {
    link[lst] = p;
    return;
  }
  if (len[q] == len[p] + 1) {
    link[lst] = q;
    return;
  }
  int clone = sz++;
  len[clone] = len[p] + 1;
  link[clone] = link[q];
  nxt[clone] = nxt[q];
  link[q] = link[lst] = clone;
  for (; nxt[p].count(c) && nxt[p][c] == q; p = link[p]) nxt[p][c] = clone;
}
void dfs(int s) {
  mk[s] = true;
  for (auto x : nxt[s])
    if (!mk[x.second]) dfs(x.second);
  topol.push_back(s);
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  string All = s + "#";
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> rule[i] >> rl[i] >> rr[i];
    All += rule[i];
    All += char(i + '#');
  }
  for (auto x : All) add(x);
  int cur = 0, cnt = 0;
  for (int i = 0; i < ((int)(All).size()); ++i) {
    cur = nxt[cur][All[i]];
    if (All[i] < 'a' || 'z' < All[i]) ver[cnt++] = cur;
  }
  for (int i = 0; i < sz; ++i)
    if (!mk[i]) dfs(i);
  for (auto v : topol) {
    for (int i = 0; i <= n; ++i) dp[i][v] = v == ver[i];
    for (auto x : nxt[v]) {
      rev[x.second].push_back(v);
      for (int i = 0; i <= n; ++i) dp[i][v] += dp[i][x.second];
    }
  }
  for (int i = 0; i < sz; ++i)
    for (int j = n; j; --j) dp[j][i] -= dp[j - 1][i];
  reverse(topol.begin(), topol.end());
  for (auto v : topol) {
    for (int i = 0; i <= n; ++i) {
      if (i == 0)
        beg[i][v] = v == 0;
      else
        beg[i][v] = v == ver[i - 1];
    }
    for (auto u : rev[v])
      for (int i = 0; i <= n; ++i) beg[i][v] += beg[i][u];
  }
  for (int i = 0; i < sz; ++i)
    for (int j = 0; j < n; ++j) beg[j][i] -= beg[j + 1][i];
  long long ans = 0;
  for (int i = 1; i < sz; ++i)
    if (dp[0][i] && i != ver[0]) {
      bool Fail = false;
      for (int j = 1; j <= n; ++j) {
        if (dp[j][i] < rl[j - 1] || dp[j][i] > rr[j - 1]) Fail = true;
      }
      if (!Fail) ans += beg[0][i];
    }
  cout << ans << '\n';
  return 0;
}
