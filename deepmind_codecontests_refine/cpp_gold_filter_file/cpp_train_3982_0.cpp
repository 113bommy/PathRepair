#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 5;
int n, m, s[100100];
long long t[100100], d[100100];
vector<pair<int, long long>> e[100100];
void dfs(int i = 0, long long l = 0) {
  d[i] = l;
  for (auto& ed : e[i]) dfs(ed.first, l + ed.second);
}
vector<pair<long long, long long>> rng;
set<int> tr[100100];
void solve(int i) {
  if (e[i].empty()) return;
  int l = 0, k = -1, f = m, dir = -1;
  for (auto& ed : e[i]) {
    solve(ed.first);
    if (((int)((tr[ed.first]).size())) > l)
      l = ((int)((tr[ed.first]).size())), k = ed.first;
    if (((int)((tr[ed.first]).size())) && *tr[ed.first].begin() < f)
      f = *tr[ed.first].begin(), dir = ed.first;
  }
  if (dir != -1 && dir != e[i].back().first) rng.push_back({1, t[f] + d[i]});
  if (k == -1) return;
  vector<pair<int, int>> ins;
  for (auto& ed : e[i])
    if (ed.first != k)
      for (int j : tr[ed.first]) ins.push_back({j, ed.first});
  sort(ins.begin(), ins.end());
  for (int j = 0; j < ((int)((ins).size())); j++) {
    auto it = tr[k].insert(ins[j].first).first;
    if (it != tr[k].begin()) {
      auto itp = it;
      itp--;
      if (j == 0 || *itp != ins[j - 1].first ||
          ins[j - 1].second != ins[j].second)
        rng.push_back({t[*itp] + d[i] + 1, t[ins[j].first] + d[i]});
    }
    auto itn = it;
    itn++;
    if (itn != tr[k].end() &&
        (j == ((int)((ins).size())) - 1 || *itn < ins[j + 1].first))
      rng.push_back({t[ins[j].first] + d[i] + 1, t[*itn] + d[i]});
  }
  for (int j : tr[i]) tr[k].insert(j);
  swap(tr[k], tr[i]);
}
pair<long long, int> cnt() {
  for (int i = 0; i < m; i++) tr[s[i]].insert(i);
  solve(0);
  sort(rng.begin(), rng.end());
  priority_queue<long long> pq;
  long long lt = 1;
  for (int i = 0; i < ((int)((rng).size())); i++) {
    while (!pq.empty() && (-pq.top() < rng[i].first || lt < rng[i].first)) {
      if (-pq.top() < lt) {
        int ccnt = 0;
        for (int j = 0; j < ((int)((rng).size())); j++)
          ccnt += rng[j].second < -pq.top();
        return {-pq.top(), ccnt};
      }
      pq.pop();
      lt++;
    }
    lt = rng[i].first;
    pq.push(-rng[i].second);
  }
  while (!pq.empty()) {
    if (-pq.top() < lt) {
      int ccnt = 0;
      for (int j = 0; j < ((int)((rng).size())); j++)
        ccnt += rng[j].second < -pq.top();
      return {-pq.top(), ccnt};
    }
    pq.pop();
    lt++;
  }
  return {-1, ((int)((rng).size()))};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m;
  int a, b;
  long long le;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> le, a--, b--;
    e[a].push_back({b, le});
  }
  for (int i = 0; i < m; i++) cin >> s[i] >> t[i], s[i]--;
  dfs();
  auto res = cnt();
  cout << res.first << " " << res.second << "\n";
}
