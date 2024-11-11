#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, ans = 1;
  pair<int, int> x[100], y[100];
  bool x1, y1, help = 0, help2;
  set<int> c;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    x[i] = pair<int, int>(a, b);
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    y[i] = pair<int, int>(a, b);
  }
  for (int i = 0; i < n; i++) {
    x1 = y1 = 0;
    if (x[i].second > x[i].first) swap(x[i].second, x[i].first);
    for (int j = 0; j < m; j++) {
      if (y[j].second > y[j].first) swap(y[j].first, y[j].second);
      if (x[i] == y[j]) continue;
      if (x[i].first == y[j].first || x[i].first == y[j].second)
        x1 = 1;
      else if (x[i].second == y[j].first || x[i].second == y[j].second)
        y1 = 1;
    }
    if (x1 && y1)
      help = 1;
    else if (x1)
      c.insert(x[i].first);
    else if (y1)
      c.insert(x[i].second);
  }
  for (int i = 0; i < m; i++) {
    x1 = y1 = 0;
    for (int j = 0; j < n; j++) {
      if (y[i] == x[i]) continue;
      if (y[i].first == x[j].first || y[i].first == x[j].second)
        x1 = 1;
      else if (y[i].second == x[j].first || y[i].second == x[j].second)
        y1 = 1;
    }
    if (x1 && y1) help = 1;
  }
  if (help || c.size() == 0)
    cout << -1;
  else if (c.size() == 1)
    cout << *c.begin();
  else
    cout << 0;
  cout << '\n';
}
