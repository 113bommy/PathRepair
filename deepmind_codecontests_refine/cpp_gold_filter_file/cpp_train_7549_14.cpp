#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<int> adj[200010], val(300010, 1), vis(300010, 0), dis1(300010, 0),
    dis2(300010, 0);
int myrandom(int i) { return std::rand() % i; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  int lo = -1, hi = (int)v.size();
  bool ok = false;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    vector<int> in(n + 1, 0);
    set<pair<int, int>> st;
    vector<int> adj[n + 1];
    for (int i = 0; i <= mid; i++) {
      st.insert(v[i]);
      in[v[i].second]++;
      adj[v[i].first].push_back(v[i].second);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
      if (in[i] == 0) {
        q.push(i);
      }
    }
    vector<int> seq;
    while (!q.empty()) {
      auto v = q.front();
      q.pop();
      seq.push_back(v);
      for (auto i : adj[v]) {
        --in[i];
        if (!in[i]) q.push(i);
      }
    }
    bool ok1 = true;
    if ((int)seq.size() == n) {
      for (int i = 0; i < n - 1; i++) {
        if (st.find({seq[i], seq[i + 1]}) == st.end()) {
          ok1 = false;
        }
      }
    } else {
      ok1 = false;
    }
    if (ok1) {
      ok = true;
      hi = mid;
    } else {
      lo = mid;
    }
  }
  if (ok) {
    cout << hi + 1 << '\n';
  } else {
    cout << -1 << '\n';
  }
}
