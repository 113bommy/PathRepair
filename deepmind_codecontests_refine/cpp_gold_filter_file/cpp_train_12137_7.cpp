#include <bits/stdc++.h>
using namespace std;
const int N = 105, maxn = 20, inf = 0x3f3f3f;
struct edge {
  int s, id;
} e[N];
bool vis[N];
bool comp(const edge &a, const edge &b) { return a.s > b.s; }
int main() {
  int n;
  queue<pair<int, int> > q;
  while (!q.empty()) q.pop();
  cin >> n;
  memset(vis, 0, sizeof(vis));
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> e[i].s;
    e[i].id = i;
    sum += e[i].s;
  }
  if (sum < n - 1 || e[1].s == 0) {
    cout << -1 << endl;
    return 0;
  }
  sort(e + 2, e + n + 1, comp);
  int i = 2, x = 1;
  while (i <= n) {
    while (e[x].s && i <= n) {
      q.push(make_pair(e[x].id, e[i].id));
      e[x].s--;
      i++;
    }
    x++;
  }
  cout << q.size() << endl;
  while (!q.empty()) {
    cout << q.front().first << " " << q.front().second << endl;
    q.pop();
  }
  return 0;
}
