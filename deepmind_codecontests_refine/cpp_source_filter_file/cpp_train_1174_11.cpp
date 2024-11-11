#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t, n, a[N], x, y, b[N];
vector<int> v[N];
queue<int> q[3];
void R(int x) {
  for (int i = 0; i < v[x].size(); ++i) {
    if (b[v[x][i]] ^ 1) {
      --b[v[x][i]];
      if (b[v[x][i]] == 1) {
        q[a[v[x][i]]].push(v[x][i]);
      }
    }
  }
}
int D(int c) {
  int dr = 0;
  for (int i = 1; i <= n; ++i) {
    b[i] = v[i].size();
  }
  for (int i = 1; i <= n; ++i) {
    if (b[i] == 1) {
      q[a[i]].push(i);
    }
  }
  while (q[0].size() || q[1].size() || q[2].size()) {
    ++dr;
    while (q[0].size() || q[c].size()) {
      if (q[0].size()) {
        R(q[0].front());
        q[0].pop();
      }
      if (q[c].size()) {
        R(q[c].front());
        q[c].pop();
      }
    }
    c = (c ^ 1 ? 1 : 2);
  }
  return dr;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  for (int ti = 1; ti <= t; ++ti) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      v[i].clear();
      cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    cout << min(D(1), D(2)) << "\n";
  }
  return 0;
}
