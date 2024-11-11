#include <bits/stdc++.h>
using namespace std;
int n, m, p[100001];
vector<pair<int, int> > g[100001];
long long d[100001];
struct comp {
  bool operator()(const int& l, const int& r) const { return d[l] < d[r]; };
};
set<int, comp> s;
void print(int i) {
  if (i != 1) print(p[i]);
  cout << i << " ";
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back(make_pair(b, w));
    g[b].push_back(make_pair(a, w));
  }
  for (int i = 1; i <= n; i++) d[i] = 1000000000000LL;
  d[1] = 0;
  s.insert(1);
  while (!s.empty()) {
    int a = *s.begin();
    s.erase(s.begin());
    for (int i = 0; i < (int)g[a].size(); i++) {
      int b = g[a][i].first;
      int w = g[a][i].second;
      if (d[a] + w < d[b]) {
        s.erase(b);
        d[b] = d[a] + w;
        p[b] = a;
        s.insert(b);
      }
    }
  }
  if (d[n] == 1000000000000LL) {
    cout << -1;
    return 0;
  }
  print(n);
}
