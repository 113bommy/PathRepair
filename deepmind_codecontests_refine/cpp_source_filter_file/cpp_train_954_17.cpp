#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, m;
vector<int> x[MAXN];
int p[MAXN], d[MAXN];
bool z[MAXN];
int ans[MAXN];
int dep[MAXN][3];
int Bfs(int s) {
  memset(z, 0, sizeof(z));
  memset(p, 0, sizeof(p));
  memset(d, 0, sizeof(d));
  queue<int> Q;
  Q.push(s);
  z[s] = true;
  while (!Q.empty()) {
    s = Q.front();
    Q.pop();
    for (int t : x[s]) {
      if (z[t]) continue;
      z[t] = true;
      p[t] = s;
      d[t] = d[s] + 1;
      Q.push(t);
    }
  }
  return s;
}
void Dfs(int a, int fa, int c, bool order) {
  ans[a] = c;
  if (order) {
    c = (c + 1) % m;
  } else {
    c = (c + m - 1) % m;
  }
  for (int b : x[a]) {
    if (b == fa) continue;
    Dfs(b, a, c, order);
  }
}
void Update(int a, int dist) {
  if (dist > dep[a][0]) {
    dep[a][2] = dep[a][1];
    dep[a][1] = dep[a][0];
    dep[a][0] = dist;
  } else if (dist + 1 > dep[a][1]) {
    dep[a][2] = dep[a][1];
    dep[a][1] = dist;
  } else if (dist + 1 > dep[a][2]) {
    dep[a][2] = dist;
  }
}
void GetD(int a, int fa) {
  for (int b : x[a]) {
    if (b == fa) continue;
    GetD(b, a);
    Update(a, dep[b][0] + 1);
  }
  if (dep[a][0] == 0) dep[a][0] = 1;
}
bool Check(int a, int fa, int df) {
  for (int b : x[a]) {
    if (b == fa) continue;
    int newdf = df + 1;
    if (dep[a][0] == dep[b][0] + 1) {
      newdf = max(newdf, dep[a][1] + 1);
    } else {
      newdf = max(newdf, dep[a][0] + 1);
    }
    if (!Check(b, a, newdf)) return false;
  }
  if (a != 1) Update(a, df);
  return dep[a][2] == 0 || dep[a][1] + dep[a][2] - 1 < m;
}
bool Check() {
  GetD(0, -1);
  return Check(0, -1, 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    x[a].push_back(b);
    x[b].push_back(a);
  }
  if (m != 2 && !Check()) {
    cout << "No" << endl;
    return 0;
  }
  int s = Bfs(0);
  int t = Bfs(s);
  int md = t;
  while (d[md] > (d[t] + 1) / 2) {
    md = p[md];
  }
  Dfs(md, p[md], 0, true);
  Dfs(p[md], md, m - 1, false);
  cout << "Yes" << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
