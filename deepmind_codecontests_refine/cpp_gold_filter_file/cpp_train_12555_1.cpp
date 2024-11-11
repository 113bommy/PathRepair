#include <bits/stdc++.h>
using namespace std;
struct nod {
  int inf;
  nod *next;
} * A[5001];
int tata[5001];
long pri[5001];
int viz[5001];
int n;
int mat[5001][5001];
int cate[5001];
int cine[5001][5001];
int rez[5001];
int x;
void add(nod *&a, int inf) {
  nod *q = new nod;
  q->inf = inf;
  q->next = a;
  a = q;
}
void citire() {
  int a, b, c;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> pri[i];
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    add(A[a], b);
    add(A[b], a);
    mat[a][b] = c;
    mat[b][a] = c;
  }
}
void bfs(int x) {
  viz[x] = 1;
  for (nod *q = A[x]; q; q = q->next)
    if (!viz[q->inf]) {
      tata[q->inf] = 1;
      bfs(q->inf);
    }
}
struct cmp {
  bool operator()(const int x, const int y) const { return pri[x] < pri[y]; }
};
void solve() {
  for (int i = 1; i <= n; i++) {
    cate[i] = 1;
    cine[i][0] = i;
  }
  int Q[5001];
  for (int i = 0;; i++) {
    for (int j = 0; j < n + 1; j++) viz[j] = 0;
    int num = 1;
    Q[0] = 1;
    viz[1] = 1;
    for (int j = 0; j < num; j++) {
      for (nod *u = A[Q[j]]; u; u = u->next)
        if (!viz[u->inf]) {
          viz[u->inf] = 1;
          for (int h = 0; h < mat[Q[j]][u->inf] && h < cate[u->inf]; h++)
            cine[Q[j]][cate[Q[j]]++] = cine[u->inf][h];
          for (int h = 0; h < cate[u->inf]; h++)
            cine[u->inf][h] = cine[u->inf][h + mat[Q[j]][u->inf]];
          cate[u->inf] -= mat[Q[j]][u->inf];
          if (cate[u->inf] < 0) cate[u->inf] = 0;
          sort(cine[u->inf], cine[u->inf] + cate[u->inf], cmp());
          sort(cine[Q[j]], cine[Q[j]] + cate[Q[j]], cmp());
          Q[num++] = u->inf;
        }
    }
    if (cate[1] == 0) {
      rez[1] = 0;
      for (int i = 1; i <= n; i++) cout << rez[i] << " ";
      return;
    }
    for (int g = 0; g < cate[1]; g++) rez[cine[1][g]] = i + 1;
    cate[1] = 0;
  }
}
int main() {
  citire();
  bfs(1);
  solve();
  return 0;
}
