#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 100 * 1000 + 10;
int n, m, a, b;
bool mark[maxn];
vector<int> alist[maxn];
int bfs(int, bool&, bool&);
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b;
    a--;
    b--;
    for (int i = 0; i < n; i++) {
      alist[i].clear();
      mark[i] = false;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      alist[u].push_back(v);
      alist[v].push_back(u);
    }
    long long acount = 0, bcount = 0;
    for (int i = 0; i < n; i++) {
      if (mark[i] || i == a || i == b) continue;
      bool seen_a = false, seen_b = false;
      int count = bfs(i, seen_a, seen_b);
      if (seen_a != seen_b) {
        acount += count * (int)seen_a;
        bcount += count * (int)seen_b;
      }
    }
    cout << acount * bcount << "\n";
  }
  return 0;
}
int bfs(int v, bool& seen_a, bool& seen_b) {
  int seen = 0;
  queue<int> q;
  mark[v] = true;
  q.push(v);
  while (!q.empty()) {
    int current = q.front();
    q.pop();
    seen++;
    for (auto u : alist[current]) {
      if (u == a)
        seen_a = true;
      else if (u == b)
        seen_b = true;
      else {
        if (!mark[u]) {
          q.push(u);
          mark[u] = true;
        }
      }
    }
  }
  return seen;
}
