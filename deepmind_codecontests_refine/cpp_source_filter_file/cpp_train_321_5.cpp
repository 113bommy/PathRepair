#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
vector<int> g[N];
int n, t, k1, k2, x, y;
int d[N];
set<int> a, b;
int bfs(int x) {
  memset(d, -1, sizeof(d));
  d[x] = 0;
  queue<int> q;
  q.push(x);
  while (q.size()) {
    int t = q.front();
    q.pop();
    for (int i : g[t]) {
      if (d[i] < 0) {
        d[i] = d[t] + 1;
        q.push(i);
      }
    }
  }
  pair<int, int> res = {N, N};
  for (int i : a) res = min(res, {d[i], i});
  return res.second;
}
void clean() {
  for (int i = 0; i < n; i++) g[i].clear();
  a.clear();
  b.clear();
}
int ask(char c, int k) {
  cout << c << " " << k << endl;
  cin >> x;
  if (x == -1) {
    assert(0);
    return (0);
  }
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    clean();
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    cin >> k1;
    for (int i = 0; i < k1; i++) cin >> x, a.insert(x);
    cin >> k2;
    for (int i = 0; i < k2; i++) cin >> x, b.insert(x);
    x = ask('B', *b.begin());
    int k = bfs(x);
    x = ask('A', k);
    if (b.count(x))
      cout << "C " << k << endl;
    else
      cout << "C -1" << endl;
  }
}
