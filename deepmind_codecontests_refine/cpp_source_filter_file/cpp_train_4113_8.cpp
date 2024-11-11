#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[444][444];
vector<pair<pair<int, int>, int> > c;
int d[444];
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return (a.second > b.second);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  n *= 2;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      cin >> x;
      c.push_back(make_pair(make_pair(i, j), x));
    }
  }
  sort(c.begin(), c.end(), cmp);
  for (int i = 0; i < c.size(); i++) {
    int u = c[i].first.first;
    int v = c[i].first.second;
    if (d[u] == 0 && d[v] == 0) {
      d[u] = v;
      d[v] = u;
    }
  }
  for (int i = 1; i <= n; i++) cout << d[i] << " ";
  return 0;
}
