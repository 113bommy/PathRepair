#include <bits/stdc++.h>
using namespace std;
long long int n, ch[300005][27], mark[300005][27], sz[300005], ans[300005],
    fans[300005];
void size_dfs(long long int v) {
  sz[v] = 1;
  for (long long int i = 1; i <= 26; ++i)
    if (ch[v][i]) {
      size_dfs(ch[v][i]);
      sz[v] += sz[ch[v][i]];
    }
}
bool cmp(long long int x, long long int y) { return sz[x] > sz[y]; }
void merge(long long int st, long long int root, long long int cur) {
  for (long long int i = 1; i <= 26; ++i)
    if (ch[cur][i]) {
      if (ch[root][i])
        merge(st, ch[root][i], ch[cur][i]);
      else {
        ch[root][i] = ch[cur][i];
        mark[root][i] = 1;
        ans[st] += sz[ch[cur][i]];
      }
    }
}
void remove(long long int root, long long int cur) {
  for (long long int i = 1; i <= 26; ++i)
    if (ch[cur][i]) {
      if (ch[root][i]) {
        if (!mark[root][i])
          remove(ch[root][i], ch[cur][i]);
        else {
          mark[root][i] = ch[root][i] = 0;
        }
      }
    }
}
void clear(long long int cur) {
  for (long long int i = 1; i <= 26; ++i) {
    if (!ch[cur][i]) continue;
    if (mark[cur][i])
      mark[cur][i] = ch[cur][i] = 0;
    else
      clear(ch[cur][i]);
  }
}
void solve(long long int st, long long int dp) {
  long long int ctch = 0;
  for (long long int i = 1; i <= 26; ++i)
    if (ch[st][i]) ctch++;
  if (ctch == 0) return;
  for (long long int i = 1; i <= 26; ++i)
    if (ch[st][i]) solve(ch[st][i], dp + 1);
  vector<long long int> tem;
  for (long long int i = 1; i <= 26; ++i)
    if (ch[st][i]) tem.push_back(ch[st][i]);
  ans[st] = n - sz[st] + 1;
  if (tem.size() == 1) {
    fans[dp] += tem.size();
    return;
  }
  sort(tem.begin(), tem.end(), cmp);
  ans[st] += sz[tem[0]];
  ans[st]--;
  for (long long int i = 1; i <= tem.size() - 1; ++i) merge(st, tem[0], tem[i]);
  for (long long int i = tem.size() - 1; i >= 1; i--) remove(tem[0], tem[i]);
  for (long long int i = tem.size() - 1; i >= 1; i--) clear(tem[i]);
  fans[dp] += (n - ans[st]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long int i = 1; i <= n - 1; ++i) {
    long long int u, v;
    char c;
    cin >> u >> v >> c;
    ch[u][c - 'a' + 1] = v;
  }
  size_dfs(1);
  solve(1, 1);
  pair<long long int, long long int> ffans = make_pair(fans[1], 1);
  for (long long int i = 1; i <= n; ++i)
    ffans = max(ffans, make_pair(fans[i], i));
  cout << n - ffans.first << '\n' << ffans.second << '\n';
}
