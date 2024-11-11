#include <bits/stdc++.h>
using namespace std;
struct SA {
  struct state {
    int len, link, nxt[26], flag = 0;
    state() : len(0), link(-1) { fill(begin(nxt), end(nxt), 0); }
  };
  vector<state> d;
  int last = 0;
  SA() { d.push_back(state()); }
  void add(char ch) {
    int cur = d.size();
    d.push_back(state());
    d[cur].len = d[last].len + 1;
    int p = last;
    while (p != -1 && !d[p].nxt[ch - 'a']) {
      d[p].nxt[ch - 'a'] = cur;
      p = d[p].link;
    }
    if (p == -1) {
      d[cur].link = 0;
    } else {
      int q = d[p].nxt[ch - 'a'];
      if (d[q].len == d[p].len + 1) {
        d[cur].link = q;
      } else {
        int clone = d.size();
        d.push_back(d[q]);
        d[clone].flag = 1;
        d[clone].len = d[p].len + 1;
        while (p != -1 && d[p].nxt[ch - 'a'] == q) {
          d[p].nxt[ch - 'a'] = clone;
          p = d[p].link;
        }
        d[cur].link = d[q].link = clone;
      }
    }
    last = cur;
  }
} sa;
const int N = 2e5 + 7;
vector<int> adj[N];
int cnt[N];
long long dp[N];
void dfs(int v) {
  for (int u : adj[v]) {
    dfs(u);
    cnt[v] += cnt[u];
  }
}
long long f(int v) {
  if (~dp[v]) return dp[v];
  long long res = 1LL * cnt[v] * cnt[v];
  for (int i = 0; i < 26; i++)
    if (sa.d[v].nxt[i]) {
      res += f(sa.d[v].nxt[i]);
    }
  return dp[v] = res;
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    sa = SA();
    for (auto ch : str) sa.add(ch);
    for (int i = 0; i < sa.d.size(); i++) {
      cnt[i] = 0;
      dp[i] = -1;
      adj[i].clear();
    }
    for (int i = 1; i < sa.d.size(); i++) {
      adj[sa.d[i].link].push_back(i);
      cnt[i] = !sa.d[i].flag;
    }
    dfs(0);
    cnt[0] = 0;
    cout << f(0) << endl;
  }
}
