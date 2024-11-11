#include <bits/stdc++.h>
using namespace std;
const int MN = 200010;
int fa[MN];
void init() {
  for (int i = 0; i < MN; i++) fa[i] = i;
}
int find(int u) {
  if (fa[u] == u)
    return u;
  else
    return fa[u] = find(fa[u]);
}
void mrg(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  fa[v] = u;
}
int N, S;
int A[MN], B[MN], P[MN], vis[MN];
int Xn;
vector<int> X;
unordered_map<int, int> dx;
vector<int> Z[MN];
set<int> V[MN];
vector<vector<int> > sol;
int main() {
  scanf("%d %d", &N, &S);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    X.push_back(A[i]);
  }
  sort(X.begin(), X.end());
  X.resize(unique(X.begin(), X.end()) - X.begin());
  Xn = X.size();
  for (int i = 0; i < Xn; i++) dx[X[i]] = i;
  for (int i = 0; i < N; i++) A[i] = dx[A[i]];
  for (int i = 0; i < N; i++) {
    B[i] = A[i];
    V[A[i]].insert(i);
  }
  sort(B, B + N);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == B[i]) {
      P[i] = i;
      V[A[i]].erase(i);
    } else {
      cnt++;
      Z[A[i]].push_back(i);
    }
  }
  if (cnt > S) {
    printf("-1");
    return 0;
  }
  for (int i = 0; i < N; i++) {
    if (A[i] != B[i]) {
      P[*V[B[i]].begin()] = i;
      V[B[i]].erase(V[B[i]].begin());
    }
  }
  init();
  for (int i = 0; i < N; i++) {
    mrg(i, P[i]);
  }
  for (int i = 0; i < Xn; i++) {
    for (int j = 0; j < (int)Z[i].size() - 1; j++) {
      int u = Z[i][j];
      int v = Z[i][j + 1];
      if (find(u) != find(v)) {
        swap(P[u], P[v]);
        mrg(u, v);
      }
    }
  }
  vector<int> tmp, pre;
  for (int i = 0; i < N; i++)
    if (P[i] != i && fa[i] == i) {
      tmp.push_back(i);
    }
  int n = min(S - cnt, (int)tmp.size());
  if (n > 1) {
    for (int i = 0; i < n; i++) {
      pre.push_back(P[tmp[i]]);
    }
    sol.push_back(vector<int>());
    for (int i = 0; i < n; i++) {
      sol.back().push_back(tmp[i]);
      P[tmp[i]] = pre[(i + n - 1) % n];
    }
  }
  for (int i = 0; i < N; i++) {
    if (vis[i]) continue;
    if (P[i] == i) continue;
    sol.push_back(vector<int>());
    int u = i;
    while (!vis[u]) {
      vis[u] = 1;
      sol.back().push_back(u);
      u = P[u];
    }
  }
  printf("%d\n", sol.size());
  for (int i = 0; i < sol.size(); i++) {
    printf("%d\n", sol[i].size());
    for (int j = 0; j < sol[i].size(); j++) {
      printf("%d ", sol[i][j] + 1);
    }
    printf("\n");
  }
}
