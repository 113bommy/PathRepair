#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 100010;
struct edge {
  int w, b, p;
  edge(int _w, int _b, int _p) {
    w = _w;
    b = _b;
    p = _p;
  }
};
bool cmp(edge a, edge b) {
  if (a.w != b.w) {
    return a.w < b.w;
  } else if (a.b != b.b) {
    return a.b < b.b;
  } else {
    return a.p < b.p;
  }
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
      int w, b;
      cin >> w >> b;
      edges.push_back(edge(w, b, i));
    }
    sort(edges.begin(), edges.end(), cmp);
    map<int, pair<int, int> > mp;
    int u = 2, from = 2, to = 3;
    bool correct = true;
    for (int i = 0; i < m; i++) {
      edge e = edges[i];
      if (e.b == 0) {
        if (to >= u) {
          correct = false;
          break;
        }
        mp[e.p] = pair<int, int>(from, to);
        from++;
        if (from == to) {
          from = 2;
          to++;
        }
      } else {
        mp[e.p] = pair<int, int>(1, u);
        u++;
      }
    }
    if (correct) {
      for (int i = 0; i < m; i++) {
        cout << mp[i].first << " " << mp[i].second << endl;
      }
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
