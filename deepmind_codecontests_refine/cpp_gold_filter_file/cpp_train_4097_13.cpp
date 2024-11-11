#include <bits/stdc++.h>
using namespace std;
const long long nax = 1e5 + 5;
vector<long long> adj[nax];
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 7;
vector<pair<char, long long>> v;
vector<char> ans;
long long visited[26];
signed main() {
  string second;
  cin >> second;
  for (long long i = 0; i < second.size(); i++) {
    v.push_back({second[i], i});
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  char cur = ' ';
  long long mx = v[0].first - 'a';
  for (long long i = 0; i < v.size(); i++) {
    cur = v[i].first;
    long long pos = v[i].second;
    if (v[i].first == cur) {
      adj[cur - 'a'].push_back(pos);
    } else {
      cur = v[i].first;
      adj[cur - 'a'].push_back(pos);
    }
  }
  for (long long i = 0; i <= mx; i++) {
    sort(adj[i].begin(), adj[i].end());
  }
  long long mx_idx = -1;
  char c = ' ';
  for (long long i = 0; i < v.size(); i++) {
    long long pos = v[i].second;
    if (visited[v[i].first - 'a'] == 1) continue;
    if (i == 0) {
      c = v[i].first;
      for (auto u : adj[c - 'a']) {
        if (mx_idx < u) {
          ans.push_back(c);
          mx_idx = max(mx_idx, u);
        }
      }
      visited[c - 'a'] = 1;
    } else {
      c = v[i].first;
      for (auto u : adj[c - 'a']) {
        if (mx_idx < u) {
          ans.push_back(c);
          mx_idx = max(mx_idx, u);
        }
      }
      visited[c - 'a'] = 1;
    }
  }
  for (auto u : ans) {
    cout << u;
  }
  cout << endl;
  return 0;
}
