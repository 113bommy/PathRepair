#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, k, trie[N][26], suf[N], fen[N], ent[N], ed[N], tme, dfstme, pol[N],
    use[N];
string s;
char c;
vector<int> v[N];
void dfs(int x) {
  ent[x] = ++dfstme;
  for (int i = 0; i < v[x].size(); ++i) dfs(v[x][i]);
  ed[x] = dfstme;
}
void up(int x, int val) {
  for (; x < N; x += x & -x) fen[x] += val;
}
void upd(int x, int val) {
  up(ent[x], val);
  up(ed[x] + 1, -val);
}
int que(int x) {
  int ret = 0;
  for (; x; x -= x & -x) ret += fen[x];
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> s;
    int cur = 0, x;
    for (int j = 0; j < s.size(); ++j) {
      x = s[j] - 'a';
      if (trie[cur][x] == 0) trie[cur][x] = ++tme;
      cur = trie[cur][x];
    }
    pol[i] = cur;
  }
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < 26; ++i) {
      if (!trie[x][i]) continue;
      int fail = suf[x];
      while (fail && !trie[fail][i]) fail = suf[fail];
      if (fail != x && trie[fail][i]) suf[trie[x][i]] = trie[fail][i];
      q.push(trie[x][i]);
      v[suf[trie[x][i]]].push_back(trie[x][i]);
    }
  }
  dfs(0);
  for (int i = 0; i < k; ++i) {
    upd(pol[i], 1);
    use[i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    cin >> c;
    if (c == '?') {
      cin >> s;
      long long ans = 0;
      int cur = 0, x;
      for (int j = 0; j < s.size(); ++j) {
        x = s[j] - 'a';
        while (cur && !trie[cur][x]) cur = suf[cur];
        cur = trie[cur][x];
        ans += que(ent[cur]);
      }
      cout << ans << '\n';
    } else {
      int x;
      cin >> x;
      if (c == '+' && use[x - 1]) continue;
      if (c == '-' && !use[x - 1]) continue;
      use[x - 1] ^= 1;
      if (c == '+')
        upd(pol[x - 1], 1);
      else
        upd(pol[x - 1], -1);
    }
  }
}
