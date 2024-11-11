#include <bits/stdc++.h>
using namespace std;
int n, m, k, first[200005], second[200005], vis[200005];
vector<int> a[200005], par[200005];
string s;
map<pair<int, int>, int> mp;
vector<string> res;
void sol(int in) {
  if (in == n + 1) {
    res.push_back(s);
    if ((int)res.size() == k) {
      cout << k << '\n';
      for (auto i : res) {
        cout << i << '\n';
      }
      exit(0);
    }
  }
  for (auto i : par[in]) {
    s[mp[{in, i}]] = '1';
    sol(in + 1);
    s[mp[{in, i}]] = '0';
  }
}
void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> first[i] >> second[i];
    a[first[i]].push_back(second[i]);
    a[second[i]].push_back(first[i]);
    mp[{first[i], second[i]}] = i;
    mp[{second[i], first[i]}] = i;
    s += '0';
  }
  queue<int> q;
  q.push(1);
  par[1].push_back(-1);
  vis[1] = 2;
  while (1) {
    set<int> st;
    while (!q.empty()) {
      int d = q.front();
      q.pop();
      for (auto i : a[d]) {
        if (vis[i] != 2) {
          par[i].push_back(d);
          ;
          vis[i] = 1;
          st.insert(i);
        }
      }
    }
    for (auto i : st) {
      q.push(i);
      vis[i] = 2;
    }
    if ((int)q.size() == 0) break;
  }
  sol(2);
  cout << (int)res.size() << '\n';
  for (auto i : res) {
    cout << i << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
