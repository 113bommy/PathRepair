#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ans;
struct Edge {
  int x, y, num, joft;
  Edge(int p, int q, int w) {
    x = p;
    y = q;
    num = w;
  }
  Edge() {}
  int other(int p) {
    if (p == y)
      return x;
    else
      return y;
  }
};
const int MAXN = 100000 + 100;
int n, m;
vector<int> v[MAXN];
Edge e[MAXN];
bool mark[MAXN];
int seen[MAXN];
void Input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    seen[i] = 0;
    e[i] = Edge(x, y, i);
    v[x].push_back(i);
    v[y].push_back(i);
  }
}
int par[MAXN];
void Dfs(int x) {
  mark[x] = true;
  for (int i = 0; i < v[x].size(); i++) {
    int u = e[v[x][i]].other(x);
    if (!mark[u]) {
      par[u] = x;
      Dfs(u);
    }
  }
  vector<int> w;
  int pp;
  for (int i = 0; i < v[x].size(); i++) {
    int u = e[v[x][i]].other(x);
    int t = v[x][i];
    if (seen[t] == 0)
      if (u != par[x]) w.push_back(t);
    if (e[v[x][i]].other(x) == par[x]) pp = v[x][i];
  }
  if (w.size() % 2 == 0) {
    for (int i = 0; i < w.size(); i += 2) {
      ans.push_back(make_pair(w[i], w[i + 1]));
      seen[w[i]] = 1;
      seen[w[i + 1]] = 1;
    }
  } else {
    for (int i = 0; i < w.size(); i += 2) {
      if (i == (w.size() - 1)) {
        ans.push_back(make_pair(w[i], pp));
        seen[pp] = 1;
        seen[w[i]] = 1;
      } else {
        ans.push_back(make_pair(w[i], w[i + 1]));
        seen[w[i]] = 1;
        seen[w[i + 1]] = 1;
      }
    }
  }
}
bool Check() {
  for (int i = 0; i < m; i++)
    if (!seen[i]) return 0;
  return 1;
}
int main() {
  Input();
  if (n % 2 == 1) {
    cout << "No solution" << endl;
    return 0;
  }
  Dfs(1);
  if (!Check() || ans.size() != (m / 2) || (m % 2) == 1)
    cout << "No solution" << endl;
  else {
    for (int i = 0; i < ans.size(); i++) {
      if (e[ans[i].first].x == e[ans[i].second].x)
        cout << e[ans[i].first].y << " " << e[ans[i].first].x << " "
             << e[ans[i].second].y << endl;
      else if (e[ans[i].first].x == e[ans[i].second].y)
        cout << e[ans[i].first].y << " " << e[ans[i].first].x << " "
             << e[ans[i].second].x << endl;
      else if (e[ans[i].first].y == e[ans[i].second].x)
        cout << e[ans[i].first].x << " " << e[ans[i].first].y << " "
             << e[ans[i].second].y << endl;
      else if (e[ans[i].first].y == e[ans[i].second].y)
        cout << e[ans[i].first].x << " " << e[ans[i].first].y << " "
             << e[ans[i].second].x << endl;
    }
  }
  return 0;
}
