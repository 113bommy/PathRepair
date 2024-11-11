#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  cin >> n >> p;
  vector<pair<int, int> > src(n + 1, make_pair(0, 0));
  vector<pair<int, int> > sink(n + 1, make_pair(0, 0));
  for (int i = 0; i < p; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    src[b] = make_pair(a, d);
    sink[a] = make_pair(b, d);
  }
  vector<pair<pair<int, int>, int> > res;
  for (int i = 1; i <= n; i++) {
    if (src[i].first) {
      continue;
    }
    int max_flow = 1000001;
    int cur = i;
    while (sink[cur].first) {
      max_flow = min(max_flow, sink[cur].second);
      cur = sink[cur].first;
    }
    if (cur != i) {
      pair<pair<int, int>, int> l = make_pair(make_pair(i, cur), max_flow);
      res.push_back(l);
    }
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first.first << " " << res[i].first.second << " "
         << res[i].second << endl;
  }
}
