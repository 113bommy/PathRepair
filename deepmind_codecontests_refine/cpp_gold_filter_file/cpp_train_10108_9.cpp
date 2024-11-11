#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct node {
  string type;
  int val, f;
} u[maxn];
vector<int> vertices[maxn];
int dfs1(int x) {
  if (u[x].type == string("IN")) return u[x].val;
  if (u[x].type == string("NOT")) {
    u[x].val = !dfs1(vertices[x][0]);
    return u[x].val;
  }
  if (u[x].type == string("AND")) {
    u[x].val = dfs1(vertices[x][0]) & dfs1(vertices[x][1]);
    return u[x].val;
  }
  if (u[x].type == string("OR")) {
    u[x].val = dfs1(vertices[x][0]) | dfs1(vertices[x][1]);
    return u[x].val;
  }
  if (u[x].type == string("XOR")) {
    u[x].val = dfs1(vertices[x][0]) ^ dfs1(vertices[x][1]);
    return u[x].val;
  }
}
void dfs2(int x) {
  if (u[x].type == string("IN"))
    return;
  else if (u[x].type == string("NOT")) {
    int v = vertices[x][0];
    if (u[x].f == 1)
      u[v].f = 1;
    else
      u[v].f = 0;
    dfs2(v);
  } else if (u[x].type == string("AND")) {
    int v1 = vertices[x][0];
    int v2 = vertices[x][1];
    if ((!u[v1].val & u[v2].val) != u[x].val && u[x].f == 1)
      u[v1].f = 1;
    else
      u[v1].f = 0;
    if ((u[v1].val & !u[v2].val) != u[x].val && u[x].f == 1)
      u[v2].f = 1;
    else
      u[v2].f = 0;
    dfs2(v1);
    dfs2(v2);
  } else if (u[x].type == string("OR")) {
    int v1 = vertices[x][0];
    int v2 = vertices[x][1];
    if ((!u[v1].val | u[v2].val) != u[x].val && u[x].f == 1)
      u[v1].f = 1;
    else
      u[v1].f = 0;
    if ((u[v1].val | !u[v2].val) != u[x].val && u[x].f == 1)
      u[v2].f = 1;
    else
      u[v2].f = 0;
    dfs2(v1);
    dfs2(v2);
  } else {
    int v1 = vertices[x][0];
    int v2 = vertices[x][1];
    if ((!u[v1].val ^ u[v2].val) != u[x].val && u[x].f == 1)
      u[v1].f = 1;
    else
      u[v1].f = 0;
    if ((u[v1].val ^ !u[v2].val) != u[x].val && u[x].f == 1)
      u[v2].f = 1;
    else
      u[v2].f = 0;
    dfs2(v1);
    dfs2(v2);
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> u[i].type;
    if (u[i].type == string("IN"))
      cin >> u[i].val;
    else if (u[i].type == string("NOT")) {
      int x;
      cin >> x;
      vertices[i].push_back(x);
    } else {
      int x, y;
      cin >> x >> y;
      vertices[i].push_back(x);
      vertices[i].push_back(y);
    }
  }
  u[1].f = 1;
  dfs1(1);
  dfs2(1);
  for (int i = 1; i <= n; i++)
    if (u[i].type == string("IN")) {
      if (u[i].f == 1)
        cout << !u[1].val;
      else
        cout << u[1].val;
    }
  return 0;
}
