#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-7;
const long long inf = 1e17;
long long n;
vector<long long> in;
vector<vector<long long> > G;
vector<long long> sum, used;
int dfs(int a) {
  used[a] = true;
  long long s = in[a];
  for (int i = 0; i < G[a].size(); i++) {
    int to = G[a][i];
    if (used[to]) continue;
    s += dfs(to);
  }
  return sum[a] = s;
}
long long out = -inf;
void dfs1(int a) {
  used[a] = true;
  vector<long long> t;
  for (int i = 0; i < G[a].size(); i++) {
    int to = G[a][i];
    if (used[to]) continue;
    dfs1(to);
    sum[a] = max(sum[a], sum[to]);
    t.push_back(-sum[to]);
  }
  sort(t.begin(), t.end());
  if (t.size() >= 2) out = max<long long>(out, -t[0] - t[1]);
}
int main() {
  cin >> n;
  in = vector<long long>(n);
  for (int i = 0; i < n; i++) cin >> in[i];
  G = vector<vector<long long> >(n);
  for (int i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  sum = vector<long long>(n);
  used = vector<long long>(n);
  dfs(0);
  used = vector<long long>(n);
  dfs1(0);
  if (out == -inf)
    cout << "Impossible" << endl;
  else
    cout << out << endl;
}
