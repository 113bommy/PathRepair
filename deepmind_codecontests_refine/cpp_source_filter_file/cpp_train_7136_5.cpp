#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, MAXM = 1005;
bitset<MAXM> All, P[MAXM];
int n, m, Q;
int start[MAXN], cnt = 0;
int Ans[MAXN];
struct Node {
  int op, x, y, id;
} T[MAXN];
struct Edge {
  int next, to;
} edge[MAXN];
void add(int from, int to) {
  cnt++;
  edge[cnt].to = to;
  edge[cnt].next = start[from];
  start[from] = cnt;
  return;
}
void DFS(int x, int from, int Now) {
  bool q = 0;
  if (T[x].op == 1) {
    q = P[T[x].x][T[x].y];
    if (P[T[x].x][T[x].y] == 0) Now++;
    P[T[x].x][T[x].y] = 1;
  }
  if (T[x].op == 2) {
    q = P[T[x].x][T[x].y];
    if (P[T[x].x][T[x].y] == 1) Now--;
    P[T[x].x][T[x].y] = 0;
  }
  if (T[x].op == 3) {
    int A = P[T[x].x].count();
    P[T[x].x] ^= All;
    Now += P[T[x].x].count() - A;
  }
  Ans[T[x].id] = Now;
  for (int i = start[x]; i; i = edge[i].next) {
    int to = edge[i].to;
    if (to != from) DFS(to, x, Now);
  }
  if (T[x].op <= 2) P[T[x].x][T[x].y] = q;
  if (T[x].op == 3) P[T[x].x] ^= All;
  return;
}
int main() {
  cin >> n >> m >> Q;
  for (int i = 1; i <= m; i++) All[i] = 1;
  for (int i = 1; i <= n; i++) P[i].reset();
  for (int i = 1; i <= Q; i++) {
    cin >> T[i].op;
    T[i].id = i;
    if (T[i].op <= 2)
      cin >> T[i].x >> T[i].y;
    else
      cin >> T[i].x;
    if (T[i].op <= 3)
      add(i - 1, i);
    else
      add(T[i].x, i);
  }
  DFS(1, 0, 0);
  for (int i = 1; i <= Q; i++) cout << Ans[i] << endl;
  return 0;
}
