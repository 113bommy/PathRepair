#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int nxi() {
  int a;
  cin >> a;
  return a;
}
vector<long long> a;
void inc(int i, long long v) {
  for (; i < a.size(); i |= i + 1) {
    a[i] = max(a[i], v);
  }
}
long long get(int r) {
  long long ans = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    ans = max(ans, a[r]);
  }
  return ans;
}
long long get(int l, int r) { return get(r) - get(l - 1); }
template <class _T>
_T gcd(_T a, _T b) {
  return a == 0 ? b : gcd(b % a, a);
}
long long bin_pow(long long a, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * a) % 1000000007;
    p /= 2;
    a = (a * a) % 1000000007;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n = nxi();
  vector<int> p(n);
  vector<pair<int, int> > edges(n);
  vector<int> used(n);
  for (auto& a : edges) {
    cin >> a.first >> a.second;
  }
  stack<int> st;
  vector<vector<pair<int, int> > > adj(1 << 20, vector<pair<int, int> >());
  for (int k = 20; k >= 0; k--) {
    used.assign(n, 0);
    for (auto& t : adj) t.clear();
    int mask = ((1 << k) - 1);
    int i = 0;
    for (auto& e : edges) {
      int l = e.first & mask, r = e.second & mask;
      adj[l].push_back({r, 2 * i + 1});
      adj[r].push_back({l, 2 * i});
      i++;
    }
    bool ok = true;
    int start_from = 0;
    for (int i = 0; i <= mask; i++) {
      if (adj[i].size()) start_from = i;
      if (adj[i].size() & 1) ok = false;
    }
    if (!ok) continue;
    vector<int> ans;
    function<void(int, int)> dfs = [&](int cur, int id) {
      while (adj[cur].size()) {
        auto v = adj[cur].back();
        adj[cur].pop_back();
        if (!used[v.second / 2]) {
          used[v.second / 2] = true;
          dfs(v.first, v.second);
        }
      }
      ans.push_back(id);
      ans.push_back(id ^ 1);
    };
    dfs(start_from, -1);
    if (ans.size() >= 2 * n) {
      ans.pop_back();
      ans.pop_back();
      cout << k << endl;
      for (int v : ans) cout << (v + 1) << ' ';
      break;
    }
  }
  return 0;
}
