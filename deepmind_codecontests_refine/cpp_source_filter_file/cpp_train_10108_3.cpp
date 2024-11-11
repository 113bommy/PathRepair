#include <bits/stdc++.h>
using namespace std;
int val[1000005], memo[1000005][5], par[1000005];
pair<int, pair<int, int> > p[1000005];
int dfs(int pos, int prv) {
  par[pos] = prv;
  if (p[pos].first == 0)
    val[pos] = 1 - dfs(p[pos].second.first, pos);
  else if (p[pos].first == 1)
    val[pos] = dfs(p[pos].second.first, pos) & dfs(p[pos].second.second, pos);
  else if (p[pos].first == 2)
    val[pos] = dfs(p[pos].second.first, pos) | dfs(p[pos].second.second, pos);
  else if (p[pos].first == 3)
    val[pos] = dfs(p[pos].second.first, pos) ^ dfs(p[pos].second.second, pos);
  else
    val[pos] = p[pos].second.first;
  return val[pos];
}
int dp(int pos, int v) {
  int ret, a, b;
  pair<int, pair<int, int> > u;
  if (pos == 1) return v;
  if (memo[pos][v] != -1) return memo[pos][v];
  u = p[par[pos]];
  if (u.first == 0)
    ret = dp(par[pos], 1 - v);
  else {
    a = val[u.second.first];
    b = val[u.second.second];
    if (u.second.first == pos)
      a = v;
    else
      b = v;
    if (u.first == 1)
      ret = dp(par[pos], a & b);
    else if (u.first == 2)
      ret = dp(par[pos], a | b);
    else
      ret = dp(par[pos], a ^ b);
  }
  memo[pos][v] = ret;
  return ret;
}
int main() {
  int n, a, b;
  char s[5];
  vector<int> v;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s %d", s, &a);
    if (s[0] == 'N')
      p[i] = make_pair(0, make_pair(a, 0));
    else if (s[0] == 'I') {
      p[i] = make_pair(4, make_pair(a, 0));
      v.push_back(i);
    } else {
      scanf("%d", &b);
      if (s[0] == 'A')
        p[i] = make_pair(1, make_pair(a, b));
      else if (s[i] == 'O')
        p[i] = make_pair(2, make_pair(a, b));
      else
        p[i] = make_pair(3, make_pair(a, b));
    }
  }
  a = dfs(1, 0);
  memset(memo, -1, sizeof memo);
  for (int x : v) printf("%d", dp(x, 1 - val[x]));
  puts("");
  return 0;
}
