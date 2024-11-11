#include <bits/stdc++.h>
using namespace std;
int rs;
long long dfs(int const* const v, int* rem, list<int>* adj, int s) {
  if (v[s] > 1 || rs == s) {
    long long ans = ((s == rs) ? 0 : 1);
    int left = ((s == rs) ? v[s] : (v[s] - 1));
    int nc = adj[s].size();
    int cons[nc];
    int chl[nc];
    int i = 0;
    for (list<int>::iterator it = adj[s].begin(); it != adj[s].end(); ++it) {
      int ch = *it;
      chl[i] = ch;
      adj[ch].remove(s);
      if (v[ch] > 0) {
        if (adj[ch].empty()) {
          cons[i] = 1;
          rem[ch] = v[ch] - 1;
        } else {
          cons[i] = dfs(v, rem, adj, ch);
        }
      } else {
        cons[i] = 0;
      }
      i++;
    }
    if (left <= nc) {
      sort(cons, cons + nc);
      reverse(cons, cons + nc);
      ans = accumulate(cons, cons + left, ans) + left;
      rem[s] = 0;
      return ans;
    } else {
      ans = accumulate(cons, cons + nc, ans) + nc;
      left -= nc;
      int df = 0;
      for (int i = 0; i < nc; ++i) df += rem[chl[i]];
      ans += 2 * min(df, left);
      left -= min(df, left);
      rem[s] = left;
      return ans;
    }
  } else {
    rem[s] = 0;
    return 1;
  }
}
int main() {
  int n;
  cin >> n;
  int v[n + 1];
  int rem[n + 1];
  fill(rem, rem + n, -1);
  for (int i = 0; i < n; ++i) cin >> v[i + 1];
  list<int> adj[n + 1];
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_front(y);
    adj[y].push_front(x);
  }
  int s;
  cin >> s;
  rs = s;
  long long ans = dfs(v, rem, adj, s);
  cout << ans << endl;
}
