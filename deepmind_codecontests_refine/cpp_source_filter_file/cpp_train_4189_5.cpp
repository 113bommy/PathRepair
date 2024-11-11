#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, d[N], b[N];
char a[N];
vector<int> v[N];
vector<int> gao(int sta) {
  priority_queue<int> q;
  for (int i = 1; i <= n; i++) {
    b[i] = d[i];
    if (!b[i]) q.push(i * sta);
  }
  vector<int> ans(n + 1, 0);
  int cnt = 0;
  while (!q.empty()) {
    int x = q.top();
    q.pop();
    ans[(abs(x))] = ++cnt;
    for (auto k : v[abs(x)]) {
      if (--b[k] == 0) q.push(k * sta);
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  for (cin >> t; t; t--) {
    cin >> n >> a + 1;
    for (int i = 1; i <= n; i++) d[i] = 0, v[i].clear();
    for (int i = 1; i < n; i++) {
      if (a[i] == '<') {
        d[i + 1]++;
        v[i].push_back(i + 1);
      } else {
        d[i]++;
        v[i + 1].push_back(i);
      }
    }
    vector<int> l = gao(1);
    vector<int> r = gao(-1);
    for (auto k : r)
      if (k) cout << k << ' ';
    cout << '\n';
    for (auto k : l)
      if (k) cout << k << ' ';
    cout << '\n';
  }
  return 0;
}
