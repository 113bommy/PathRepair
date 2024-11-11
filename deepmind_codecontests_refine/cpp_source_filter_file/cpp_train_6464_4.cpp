#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 5;
vector<pair<long long, long long> > adj[N];
long long tiw, ta[N], tf[N];
int vt[N];
short mrk[N] = {0, 1};
bool ISLESS(
    const pair<pair<long long, long long>, pair<long long, long long> > &a,
    const pair<pair<long long, long long>, pair<long long, long long> > &b) {
  if ((long long)a.first.second * b.first.first >
      (long long)a.first.first * b.first.second)
    return true;
  return false;
}
void upfs(const int &v) {
  vector<pair<pair<long long, long long>, pair<long long, long long> > > tmp;
  vt[v] = 1;
  for (int i = 0; i < adj[v].size(); ++i) {
    int u = adj[v][i].second;
    int c = adj[v][i].first;
    if (!mrk[u]++) {
      upfs(u);
      vt[v] += vt[u];
      tf[u] += 2 * c;
      tmp.push_back(make_pair(make_pair(tf[u], vt[u]), adj[v][i]));
    }
  }
  sort(tmp.begin(), tmp.end(), ISLESS);
  adj[v].clear();
  for (int i = 0; i < tmp.size(); ++i) {
    adj[v].push_back(tmp[i].second);
    tf[v] += tf[tmp[i].second.second];
  }
}
void dfs(const int &v) {
  ta[v] = tiw;
  for (int i = 0; i < adj[v].size(); ++i) {
    if (!mrk[adj[v][i].second]++) {
      tiw += adj[v][i].first;
      dfs(adj[v][i].second);
      tiw += adj[v][i].first;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  int n, a, b, cost;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b >> cost;
    adj[a].push_back(make_pair(cost, b));
    adj[b].push_back(make_pair(cost, a));
  }
  upfs(1);
  fill(mrk + 2, mrk + N, 0);
  dfs(1);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) sum += ta[i];
  cout << (double)sum / (n - 1) << endl;
  return 0;
}
