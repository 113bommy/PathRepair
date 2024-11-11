#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v[200005];
vector<long long> w;
long long a[200005], d[200005], n, i, x, c, sol[200005], dp[200005][100],
    tata[200005], nod, pas;
void df(int nod, long long l) {
  d[nod] = l;
  for (auto it : v[nod]) df(it.first, l + it.second);
}
void df(int nod) {
  dp[nod][0] = tata[nod];
  x = tata[tata[nod]];
  int y;
  y = 1;
  while (x) {
    dp[nod][y] = x;
    x = dp[x][y];
    y++;
  }
  for (auto it : v[nod]) df(it.first);
}
void dfs(int nod) {
  for (auto it : v[nod]) {
    dfs(it.first);
    sol[nod] += sol[it.first];
  }
}
int main() {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 2; i <= n; i++) {
    cin >> x >> c;
    tata[i] = x;
    v[x].push_back(make_pair(i, c));
  }
  df(1, 0);
  df(1);
  for (i = 1; i <= n; i++) {
    nod = i;
    x = i;
    pas = log2(n);
    while (pas >= 0 && dp[nod][pas] == 0) pas--;
    while (pas >= 0) {
      if (dp[nod][pas] && d[i] - d[dp[nod][pas]] <= a[i]) {
        nod = dp[nod][pas];
      }
      pas--;
    }
    sol[tata[nod]]--;
    sol[tata[i]]++;
  }
  dfs(1);
  for (i = 1; i <= n; i++) cout << sol[i] << ' ';
  return 0;
}
