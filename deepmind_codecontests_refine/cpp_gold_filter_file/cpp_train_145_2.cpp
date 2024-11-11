#include <bits/stdc++.h>
using namespace std;
const int N_ = 100005;
int N, M;
vector<int> Gph[N_], Child[N_];
int depth[N_];
bool visited[N_];
int W[N_];
vector<int> res;
void ins(int a, int b, int c) {
  res.push_back(a);
  res.push_back(b);
  res.push_back(c);
}
void DFS(int u, int p, int d) {
  visited[u] = true;
  depth[u] = d;
  vector<int> rev;
  for (int i = 0; i < Gph[u].size(); i++) {
    int v = Gph[u][i];
    if (!visited[v])
      Child[u].push_back(v), DFS(v, u, d + 1);
    else if (v != p && depth[v] > depth[u])
      rev.push_back(v);
  }
  for (int i = 0; i < rev.size(); i += 2) {
    if (i + 1 >= rev.size())
      W[u] = rev[i];
    else
      ins(rev[i], u, rev[i + 1]);
  }
}
bool processW(int u, int p) {
  if (Child[u].empty()) return true;
  vector<int> remained;
  for (int i = 0; i < Child[u].size(); i++) {
    int v = Child[u][i];
    if (processW(v, u)) {
      if (W[v] == 0)
        remained.push_back(v);
      else
        ins(u, v, W[v]);
    }
  }
  int nd = 0;
  for (int i = 0; i < remained.size(); i += 2) {
    if (i + 1 >= remained.size())
      nd = remained[i];
    else
      ins(remained[i], u, remained[i + 1]);
  }
  if (nd > 0) {
    if (W[u] == 0) {
      if (p != -1) ins(nd, u, p);
      return false;
    } else {
      ins(nd, u, W[u]);
      W[u] = 0;
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    Gph[u].push_back(v);
    Gph[v].push_back(u);
  }
  DFS(1, -1, 0);
  processW(1, -1);
  if (res.size() / 3 * 2 != M)
    puts("No solution");
  else {
    for (int i = 0; i < res.size(); i += 3) {
      for (int j = 0; j < 3; j++) printf("%d ", res[i + j]);
      puts("");
    }
  }
  return 0;
}
