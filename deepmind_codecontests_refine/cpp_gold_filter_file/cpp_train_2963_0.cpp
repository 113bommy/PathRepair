#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
map<string, int> mp;
pair<int, int> r[100001];
priority_queue<pair<pair<int, int>, int>> pq;
bool vis[100001];
int rd(string s) {
  if (mp[s]) {
    return mp[s];
  }
  mp[s] = mp.size() + 1;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'r') {
      cnt++;
    }
  }
  r[mp[s]] = {-cnt, -s.size()};
  pq.push({{-cnt, -s.size()}, mp[s]});
  return mp[s];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<int> v;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      s[i] = tolower(s[i]);
    }
    v.push_back(rd(s));
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
      s1[i] = tolower(s1[i]);
    }
    for (int i = 0; i < s2.size(); i++) {
      s2[i] = tolower(s2[i]);
    }
    int u, v;
    u = rd(s1);
    v = rd(s2);
    adj[v].push_back(u);
  }
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = true;
    for (int v : adj[u]) {
      if (r[u] > r[v]) {
        r[v] = r[u];
        pq.push({r[v], v});
      }
    }
  }
  long long ans1 = 0, ans2 = 0;
  for (int i : v) {
    ans1 -= r[i].first;
    ans2 -= r[i].second;
  }
  cout << ans1 << " " << ans2;
}
