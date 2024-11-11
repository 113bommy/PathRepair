#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Edge {
 public:
  int from, to, value;
  Edge(ll a, ll b, ll c) {
    from = a;
    to = b;
    value = c;
  }
  Edge(ll a, ll b) {
    from = a;
    to = b;
  }
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    set<int> p;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      v.push_back({a, i});
    }
    for (int i = 0; i < m; i++) {
      int a;
      cin >> a;
      p.insert(a);
    }
    sort(v.begin(), v.end());
    bool f = true;
    for (int i = 0; i < n; i++) {
      int mi = min(v[i].second, i);
      int ma = max(v[i].second, i);
      if (mi == ma) continue;
      for (int i = mi; i < ma - 1; i++) {
        if (p.find(i + 1) == p.end()) f = false;
      }
    }
    cout << (f ? "YES" : "NO") << endl;
  }
}
