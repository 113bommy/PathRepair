#include <bits/stdc++.h>
using namespace std;
const double pai = acos(-1);
const double eps = 1e-10;
const long long mod = 1e9 + 7;
const int MXN = 1e6 + 5;
vector<int> v, tr[MXN], g[MXN];
int col[MXN];
void bfs(int x, int id) {
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    tr[id].push_back(now);
    for (auto i : g[now]) col[i] = now;
    for (int i = 0; i < (int)v.size(); i++) {
      if (col[v[i]] != now) {
        g[id].push_back(v[i]);
        q.push(v[i]);
        swap(v[i], v.back());
        v.pop_back();
        i--;
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int sa, sb;
    scanf("%d %d", &sa, &sb);
    g[sa].push_back(sb);
    g[sb].push_back(sa);
  }
  for (int i = 1; i <= n; i++) v.push_back(i);
  int cnt_cc = 0;
  while ((int)v.size()) {
    int now = v.back();
    v.pop_back();
    bfs(now, ++cnt_cc);
  }
  cout << cnt_cc - 1 << '\n';
  return 0;
}
