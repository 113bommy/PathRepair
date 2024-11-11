#include <bits/stdc++.h>
using namespace std;
inline void SetIO(string Name) {
  string Input = Name + ".in", Output = Name + ".out";
  freopen(Input.c_str(), "r", stdin), freopen(Output.c_str(), "w", stdout);
}
const int N = 100010, M = 200010;
int First[N], To[M], Use[M], Next[M], Tot;
int n, m;
inline void Insert(int u, int v) {
  To[Tot] = v, Next[Tot] = First[u];
  First[u] = Tot++;
}
inline void Input() {
  scanf("%d%d", &n, &m);
  if (m & 1) {
    puts("No solution");
    exit(0);
  }
  for (int i = (1); i <= (n); i++) First[i] = -1;
  for (int i = (1); i <= (m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    Insert(u, v), Insert(v, u);
  }
}
inline int Search(int u) {
  int Tab, v, w;
  vector<int> Que, Unpair;
  for (Tab = First[u]; Tab != -1; Tab = Next[Tab])
    if (!Use[Tab]) {
      Use[Tab] = Use[Tab ^ 1] = 1;
      Que.push_back(To[Tab]);
    }
  for (int i = (0); i < (((int)(Que).size())); i++) {
    w = Search(v = Que[i]);
    if (w)
      printf("%d %d %d\n", u, v, w);
    else
      Unpair.push_back(v);
  }
  for (Tab = 1; Tab < ((int)(Unpair).size()); Tab += 2)
    printf("%d %d %d\n", Unpair[Tab - 1], u, Unpair[Tab]);
  if (((int)(Unpair).size()) & 1) return Unpair.back();
  return 0;
}
inline void Solve() { Search(1); }
int main() {
  Input();
  Solve();
  return 0;
}
