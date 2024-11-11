#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 300010;
int rank1[MAXSIZE];
int parent[MAXSIZE];
int visited[MAXSIZE];
int diameter[MAXSIZE];
int N;
vector<int> V[MAXSIZE];
int maxL = 0, last = 0;
int FindSet(int x) {
  if (x != parent[x]) parent[x] = FindSet(parent[x]);
  return parent[x];
}
void Union(int root1, int root2) {
  int x = FindSet(root1), y = FindSet(root2);
  if (x == y) return;
  if (rank1[x] > rank1[y])
    parent[y] = x;
  else {
    parent[x] = y;
    if (rank1[x] == rank1[y]) ++rank1[y];
  }
}
void Union1(int root1, int root2) {
  int x = FindSet(root1), y = FindSet(root2);
  if (x == y) return;
  if (rank1[x] > rank1[y])
    parent[y] = x;
  else {
    parent[x] = y;
    if (rank1[x] == rank1[y]) ++rank1[y];
  }
  diameter[FindSet(x)] =
      max((double)max(diameter[x], diameter[y]),
          ceil(diameter[x] / 2.0) + ceil(diameter[y] / 2.0) + 1);
}
void Init() {
  memset(rank1, 0, sizeof(rank1));
  for (int i = 0; i < MAXSIZE; ++i) parent[i] = i;
}
void dfs(int v, int path, int p) {
  if (path > maxL) {
    maxL = path;
    last = v;
  }
  for (int i = 0; i < V[v].size(); i++) {
    int to = V[v][i];
    if (to != p) dfs(V[v][i], path + 1, v);
  }
}
int nextInt() {
  int x = 0, p = 1;
  char c;
  do {
    c = getchar();
  } while (c <= 32);
  if (c == '-') {
    p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * p;
}
void solve() {
  int m, q;
  N = nextInt();
  m = nextInt();
  q = nextInt();
  Init();
  for (int i = 0; i < m; i++) {
    int p, q;
    p = nextInt();
    q = nextInt();
    p--, q--;
    Union(p, q);
    V[p].push_back(q);
    V[q].push_back(p);
  }
  memset(diameter, -1, sizeof(diameter));
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < N; i++) {
    int setIbelongs = FindSet(i);
    if (!visited[setIbelongs]) {
      visited[setIbelongs] = 1;
      maxL = -1;
      dfs(i, 0, -1);
      maxL = -1;
      dfs(last, 0, -1);
      diameter[setIbelongs] = maxL;
    }
  }
  int x, y, p;
  while (q--) {
    p = nextInt();
    x = nextInt();
    x--;
    if (p == 1) {
      printf("%d\n", diameter[FindSet(x)]);
    } else {
      y = nextInt();
      y--;
      Union1(x, y);
    }
  }
}
int main() {
  Init();
  solve();
}
