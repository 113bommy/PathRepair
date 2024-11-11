#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return a < 0 ? (-a) : a;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
struct Node {
  vector<int> to;
  bool was;
  Node() : was(false) {}
};
vector<Node> g;
int n;
void DFS(int i, int from) {
  if (g[i].was) return;
  g[i].was = true;
  for (int j = 0; j < (g[i].to.size()); ++j) {
    int to = g[i].to[j];
    if (g[to].was) continue;
    DFS(to, i);
    return;
  }
}
int cur;
bool cmp(int to1, int to2) {
  if (g[to1].to.size() != g[to2].to.size()) {
    if (g[to1].to.size() < g[to2].to.size() && g[to1].to.size() != 1)
      return true;
    return false;
  } else
    return to1 > to2;
}
int main() {
  int m;
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < (m); ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (a == b || find((g[a].to).begin(), (g[a].to).end(), b) != g[a].to.end())
      continue;
    g[a].to.push_back(b);
    g[b].to.push_back(a);
  }
  for (int i = 0; i < (n); ++i) {
    cur = i;
    sort((g[i].to).begin(), (g[i].to).end(), cmp);
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      g[j].was = false;
    }
    DFS(i, -1);
    bool ok = true;
    for (int j = 0; j < (n); ++j) {
      if (!g[j].was) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
