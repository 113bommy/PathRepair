#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
int L[MAXN];
int R[MAXN];
int Arr[MAXN];
bool Depth[MAXN];
vector<int> Edge[MAXN];
int Tree0[MAXN];
int Tree1[MAXN];
int N, M;
int idx = 0;
int lowbit(int x) { return x & (-x); }
void Add(int Pos, int Num, int Tree[]) {
  for (int i = Pos; i <= N; i += lowbit(i)) {
    Tree[i] += Num;
  }
}
int Sum(int Pos, int Tree[]) {
  int sum = 0;
  for (int i = Pos; i > 0; i -= lowbit(i)) {
    sum += Tree[i];
  }
  return sum;
}
void DFS(int u, int f, bool depth) {
  L[u] = ++idx;
  Depth[u] = depth;
  for (int i = Edge[u].size() - 1; i >= 0; i--) {
    if (f != Edge[u][i]) {
      DFS(Edge[u][i], u, !depth);
    }
  }
  R[u] = idx;
}
int main(void) {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> Arr[i];
  }
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    Edge[u].push_back(v);
    Edge[v].push_back(u);
  }
  DFS(1, 0, 0);
  for (int i = 0; i < M; i++) {
    int ins, x, Val;
    cin >> ins;
    switch (ins) {
      case 1: {
        cin >> x >> Val;
        if (!Depth[x]) {
          Add(L[x], Val, Tree0);
          Add(R[x] + 1, -Val, Tree0);
        } else {
          Add(L[x], Val, Tree1);
          Add(R[x] + 1, -Val, Tree1);
        }
        break;
      }
      case 2: {
        cin >> x;
        if (!Depth[x]) {
          cout << Arr[x] + Sum(L[x], Tree0) - Sum(L[x], Tree1) << endl;
        } else {
          cout << Arr[x] + Sum(L[x], Tree1) - Sum(L[x], Tree0) << endl;
        }
        break;
      }
    }
  }
  return 0;
}
