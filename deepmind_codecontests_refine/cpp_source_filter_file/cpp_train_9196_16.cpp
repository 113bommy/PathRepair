#include <bits/stdc++.h>
using namespace std;
const int N = 8 * (int(1e5) + 5);
int n, k, h[N];
bool mark[N], ans = false, open[N];
vector<int> g[N];
int q[N];
int nu;
void bfs() {
  int head = 0, tail = 0;
  mark[0] = true;
  for (int i = 0; i < g[0].size(); i++) {
    q[tail++] = g[0][i];
    h[g[0][i]] = 1;
  }
  while (head != tail) {
    if (mark[head]) {
      head++;
      continue;
    }
    int cur = q[head];
    if (cur == 2 * n) {
      ans = true;
      return;
    }
    mark[cur] = true;
    for (int i = 0; i < g[cur].size(); i++) {
      nu = g[cur][i];
      if (!mark[nu] && ((nu % n) > h[cur] || nu == 2 * n)) {
        q[tail++] = nu;
        h[nu] = h[cur] + 1;
      }
    }
    head++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  string s1, s2, s;
  cin >> s1 >> s2;
  s = s1 + s2;
  open[2 * n] = true;
  for (int i = 0; i < 2 * n; i++)
    if (s[i] == '-') open[i] = true;
  for (int i = 0; i < n; i++) {
    if (i < n - 1 && open[i + 1]) g[i].push_back(i + 1);
    if (i > 0 && open[i - 1]) g[i].push_back(i - 1);
    if (i + k >= n)
      g[i].push_back(2 * n);
    else if (open[n + i + k])
      g[i].push_back(n + i + k);
  }
  for (int i = n; i < 2 * n; i++) {
    if (open[i + 1]) g[i].push_back(i + 1);
    if (i > n && open[i - 1]) g[i].push_back(i - 1);
    if (i + k >= 2 * n)
      g[i].push_back(2 * n);
    else if (open[i + k - n])
      g[i].push_back(i + k - n);
  }
  bfs();
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
