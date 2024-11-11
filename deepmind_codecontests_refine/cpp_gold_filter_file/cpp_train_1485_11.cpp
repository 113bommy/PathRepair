#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int mn = 2e5 + 7;
vector<int> a(mn), k(mn);
vector<pair<int, int> > b(mn);
vector<vector<int> > c(mn);
vector<bool> vis(mn, false);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= (n); ++i) {
    cin >> a[i];
    k[i] = a[i];
  }
  for (int i = 1; i <= (m); ++i) {
    cin >> b[i].first >> b[i].second;
    k[b[i].first]--;
    k[b[i].second]--;
    c[b[i].first].push_back(i);
    c[b[i].second].push_back(i);
  }
  queue<int> q;
  stack<int> st;
  for (int i = 1; i <= (n); ++i) {
    if (k[i] >= 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int x : c[t]) {
      if (vis[x]) {
        continue;
      }
      vis[x] = 1;
      k[b[x].first]++;
      k[b[x].second]++;
      if (k[b[x].first] == 0) {
        q.push(b[x].first);
      }
      if (k[b[x].second] == 0) {
        q.push(b[x].second);
      }
      st.push(x);
    }
  }
  if (st.size() < m) {
    cout << "DEAD";
  } else {
    cout << "ALIVE" << endl;
    while (!st.empty()) {
      cout << st.top() << " ";
      st.pop();
    }
  }
  return 0;
}
