#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int p[1000001] = {0};
long long int len[1000001] = {0};
long long int component[1000001] = {0};
long long int idx[1000001] = {0};
bool vis[1000001] = {0};
long long int q[1000001] = {0};
map<pair<long long int, long long int>, long long int> mp;
vector<long long int> s[1000001];
map<long long int, long long int> pos;
void solve() {
  cin >> n;
  for (long long int j = 1; j <= n; j++) cin >> p[j];
  long long int c = 0;
  for (long long int j = 1; j <= n; j++) {
    if (vis[p[j]]) {
      continue;
    }
    long long int l = 1;
    c++;
    component[p[j]] = c;
    vis[p[j]] = 1;
    idx[p[j]] = 0;
    mp[{c, 0}] = p[j];
    if (p[j] == j) {
      len[c] = 1;
      continue;
    }
    long long int i = 1;
    long long int k = p[p[j]];
    while (true) {
      l++;
      vis[k] = 1;
      idx[k] = i++;
      component[k] = c;
      mp[{c, idx[k]}] = k;
      if (k == j) break;
      k = p[k];
    }
    len[c] = l;
    pos[c] = (long long int)s[l].size();
    s[l].push_back(c);
  }
  for (long long int j = 1; j <= n; j++) {
    long long int m = len[component[j]];
    if (m == 1) {
      q[j] = p[j];
    } else if (m % 2 == 1) {
      q[j] = mp[{component[j], ((m - 1) / 2 + idx[j] + 1) % m}];
    } else {
      if ((long long int)s[m].size() % 2) {
        cout << -1 << "\n";
        return;
      } else {
        if (pos[component[j]] % 2 == 0) {
          q[j] = mp[{s[m][pos[component[j]] + 1], idx[j]}];
        } else {
          q[j] =
              mp[{s[m][(pos[component[j]] - 1) % ((long long int)s[m].size())],
                  (idx[j] + 1) % m}];
        }
      }
    }
  }
  for (long long int j = 1; j <= n; j++) {
    cout << q[j] << " ";
  }
  cout << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
