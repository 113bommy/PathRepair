#include <bits/stdc++.h>
using namespace std;
const int Alpha = 31;
long long mminN;
class SuffixAutomata {
 public:
  struct state {
    int len, link;
    int next[Alpha];
    int tot[3];
    state() {
      len = link = tot[0] = tot[1] = tot[2] = 0;
      memset(next, -1, sizeof(next));
    }
  };
  int sz = 1, last = 0;
  vector<state> st;
  vector<long long> vis;
  vector<int> terminal;
  void Init(int len) {
    st.clear();
    terminal.clear();
    st.resize(2 * len);
    terminal.resize(2 * len);
    sz = 1;
    last = 0;
    st[0].len = 0;
    st[0].link = -1;
  }
  void extend(char ccc) {
    int c = ccc - 'a';
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && st[p].next[c] == -1) {
      st[p].next[c] = cur;
      p = st[p].link;
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].next[c];
      if (st[p].len + 1 == st[q].len) {
        st[cur].link = q;
      } else {
        int clone = sz++;
        st[clone].len = st[p].len + 1;
        for (int j = 0; j < Alpha; j++) st[clone].next[j] = st[q].next[j];
        st[clone].link = st[q].link;
        while (p != -1 && st[p].next[c] == q) {
          st[p].next[c] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
  void getTerminal() {
    int p = last;
    while (p > 0) terminal[p] = 1, p = st[p].link;
  }
  void build(string s) {
    Init(s.size());
    for (auto x : s) extend(x);
    getTerminal();
  }
  void dfs(int v, int tp) {
    vis[v] = 1;
    st[v].tot[tp] = 1;
    for (int i = 0; i < 26; i++) {
      long long to = st[v].next[i];
      if (to != -1 && vis[to] == 0) {
        dfs(to, tp);
      }
    }
  }
  long long dp[300100];
  void solve() {
    vis.resize(st.size());
    dfs(st[0].next['{' - 'a'], 0);
    vis.clear();
    vis.resize(st.size());
    dfs(st[0].next['|' - 'a'], 1);
    vis.clear();
    vis.resize(st.size());
    dfs(st[0].next['}' - 'a'], 2);
    vector<pair<long long, long long> > ww;
    for (int i = 0; i < st.size(); i++) {
      if (st[i].len > 0) {
        ww.push_back({st[i].len, i});
      }
    }
    sort(ww.rbegin(), ww.rend());
    for (int i = 0; i < ww.size(); i++) {
      long long id = ww[i].second;
      long long to = st[id].link;
      if (to != -1) {
        for (int j = 0; j < 3; j++) {
          st[to].tot[j] += st[id].tot[j];
          st[to].tot[j] %= 1000000007;
        }
      }
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < st.size(); i++) {
      long long sol =
          ((st[i].tot[0] * st[i].tot[1]) % 1000000007) * st[i].tot[2];
      sol %= 1000000007;
      long long maxLen = st[i].len;
      long long minLen = st[st[i].link].len + 1;
      dp[minLen] += sol;
      dp[minLen] %= 1000000007;
      dp[maxLen + 1] += 1000000007;
      dp[maxLen + 1] -= sol;
      dp[maxLen + 1] %= 1000000007;
    }
    long long tot = 0;
    for (int i = 1; i <= mminN; i++) {
      tot += dp[i];
      tot %= 1000000007;
      dp[i] = tot;
      if (i != mminN)
        cout << dp[i] << " ";
      else
        cout << dp[i] << endl;
    }
    return;
  }
};
int main() {
  ios::sync_with_stdio(false);
  SuffixAutomata x;
  string s1;
  string s2;
  string s3;
  cin >> s1;
  cin >> s2;
  cin >> s3;
  mminN = min(s1.length(), s2.length());
  mminN = min(mminN, (long long)s3.length());
  string s = "{" + s1 + "|" + s2 + "}" + s3;
  x.build(s);
  x.solve();
  return 0;
}
