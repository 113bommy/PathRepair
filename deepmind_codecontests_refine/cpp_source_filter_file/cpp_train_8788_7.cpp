#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int n, m, k;
vector<long long int> type;
vector<vector<pair<long long int, long long int> > > g;
vector<long long int> groups;
long long int cnt;
vector<long long int> visited;
void dfs(long long int s, long long int t) {
  visited[s] = 1;
  if (type[s] == t) cnt++;
  for (auto it : g[s]) {
    if (!visited[it.first] && it.second == 0) dfs(it.first, t);
  }
}
int main() {
  srand(chrono::steady_clock::now().time_since_epoch().count());
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  g.resize(n);
  type.resize(n);
  groups.resize(k);
  for (__typeof(k) i = (0) - ((0) > (k)); i != (k) - ((0) > (k));
       i += 1 - 2 * ((0) > (k)))
    cin >> groups[i];
  long long int ind = 0;
  for (long long int i = 0; i < k; i++) {
    for (long long int j = 0; j < groups[i]; j++) {
      type[ind] = i;
      ind++;
    }
  }
  for (__typeof(k) i = (1) - ((1) > (k)); i != (k) - ((1) > (k));
       i += 1 - 2 * ((1) > (k))) {
    groups[i] += groups[i - 1];
  }
  long long int a, b, c;
  for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
       i += 1 - 2 * ((0) > (m))) {
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back(make_pair(b, c));
    g[b].push_back(make_pair(a, c));
  }
  long long int ok = 1;
  for (long long int i = 0; i < k; i++) {
    visited.clear();
    visited.resize(n, 0);
    long long int beg = (i == 0) ? 0 : groups[i - 1];
    long long int collect = i == 0 ? groups[0] : (groups[i] - groups[i - 1]);
    cnt = 0;
    dfs(beg, i);
    if (cnt != collect) ok = 0;
  }
  if (ok) {
    cout << "Yes\n";
    vector<vector<long long int> > dd(k, vector<long long int>(k, INT_MAX));
    for (long long int i = 0; i < n; i++) {
      for (auto it : g[i]) {
        long long int t1 = type[i];
        long long int t2 = type[it.first];
        dd[t1][t2] = min(dd[t1][t2], it.second);
        dd[t2][t1] = min(dd[t2][t1], it.second);
      }
    }
    for (long long int i = 0; i < k; i++) dd[i][i] = 0;
    for (long long int p = 1; p < k; ++p) {
      for (long long int i = 0; i < k; ++i) {
        for (long long int j = 0; j < k; ++j) {
          dd[i][j] = min(dd[i][j], dd[i][p] + dd[p][j]);
        }
      }
    }
    for (__typeof(k) i = (0) - ((0) > (k)); i != (k) - ((0) > (k));
         i += 1 - 2 * ((0) > (k))) {
      for (__typeof(k) j = (0) - ((0) > (k)); j != (k) - ((0) > (k));
           j += 1 - 2 * ((0) > (k))) {
        if (dd[i][j] == INT_MAX)
          cout << -1 << " ";
        else
          cout << dd[i][j] << " ";
      }
      cout << "\n";
    }
  } else
    cout << "No";
  return 0;
}
