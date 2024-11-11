#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 5;
int n, m, q, diam, l, A[MAX], P[MAX], T[MAX], L[MAX], mark[MAX];
vector<int> G[MAX];
int dfs(int nod, int r) {
  A[++l] = nod;
  mark[nod] = 1;
  if (nod != r && G[nod].size() == 1) return 0;
  int a = -1, b = -1;
  for (int i = 0; i < G[nod].size(); i++) {
    int newn = G[nod][i];
    if (mark[newn]) continue;
    int d = dfs(newn, r);
    if (d > a) {
      b = a;
      a = d;
      continue;
    }
    if (d > b) b = d;
  }
  diam = max(diam, a + b + 2);
  return a + 1;
}
int findst(int x) {
  if (x == P[x]) return x;
  P[x] = findst(P[x]);
}
void joinst(int a, int b) {
  a = findst(a);
  b = findst(b);
  if (a == b) return;
  if (T[b] > T[a]) swap(a, b);
  P[b] = a;
  T[a] += T[b];
  int d = max(L[a], L[b]);
  L[a] = max(d, (L[a] + 1) / 2 + (L[b] + 1) / 2 + 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) P[i] = i, T[i] = 1;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
    joinst(a, b);
  }
  for (int i = 1; i <= n; i++) {
    if (!mark[i]) {
      diam = l = 0;
      dfs(i, i);
      for (int j = 1; j <= l; j++) L[A[j]] = diam;
    }
  }
  while (q--) {
    int op, a, b;
    scanf("%d%d", &op, &a);
    if (op == 1) {
      int x = findst(a);
      printf("%d\n", L[x]);
    } else {
      scanf("%d", &b);
      joinst(a, b);
    }
  }
  return 0;
}
