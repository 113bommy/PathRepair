#include <bits/stdc++.h>
using namespace std;
long long int n, k, p, in[1007], cnt;
vector<string> u[1007], v;
vector<long long int> adj[30];
bool occ[30];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (long long int i = 0; i < n; ++i) {
    cin >> p;
    for (long long int j = 0; j < k; ++j) {
      string s;
      cin >> s;
      u[p].push_back(s);
      for (char c : s)
        if (!occ[c - 'a']) {
          occ[c - 'a'] = 1;
          cnt++;
        }
    }
  }
  for (long long int i = 0; i < n; ++i) {
    for (auto j : u[i]) v.push_back(j);
  }
  for (long long int i = 0; i < n * k - 1; ++i) {
    string s = v[i], t = v[i + 1];
    bool ok = 0;
    for (long long int j = 0;
         j < min((long long int)s.size(), (long long int)t.size()); ++j) {
      if (s[j] != t[j]) {
        adj[s[j] - 'a'].push_back(t[j] - 'a');
        in[t[j] - 'a']++;
        ok = 1;
        break;
      }
    }
    if (!ok && (long long int)t.size() < (long long int)s.size()) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  vector<long long int> ans;
  queue<long long int> ben;
  for (long long int i = 0; i < 26; ++i) {
    if (!in[i] && occ[i]) ben.push(i);
  }
  while (!ben.empty()) {
    long long int x = ben.front();
    ben.pop();
    ans.push_back(x);
    for (long long int i : adj[x]) {
      in[i]--;
      if (!in[i]) ben.push(i);
    }
  }
  if ((long long int)ans.size() < cnt)
    cout << "IMPOSSIBLE\n";
  else {
    for (long long int i : ans) cout << char(i + 'a');
    cout << '\n';
  }
  return 0;
}
