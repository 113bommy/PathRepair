#include <bits/stdc++.h>
using namespace std;
int v[100001];
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > a;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({min(x, y), max(x, y)});
    v[x] = v[y] = 1;
  }
  int d1 = n + 1, d2 = 0;
  for (int i = 0; i < m; i++)
    d2 = max(d2, a[i].first), d1 = min(d1, a[i].second);
  if (d1 <= d2) return cout << 0, 0;
  int s = 1;
  for (int i = 1; i <= n; i++) {
    if (v[i] == 0) {
      if (i > d2 && i < d1) s++;
    }
  }
  if (m == 0) s -= 2;
  cout << s << endl;
}
