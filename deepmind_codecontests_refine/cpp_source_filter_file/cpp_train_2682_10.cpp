#include <bits/stdc++.h>
const int MaxN = 10000;
using namespace std;
vector<int> V[MaxN * 4 + 5];
bitset<MaxN + 5> A, res, tmp[MaxN * 4 + 5];
void Insert(int l, int r, int t, int L, int R, int w) {
  if (l == L && r == R) {
    V[t].push_back(w);
    return;
  }
  int mid = (l + r) >> 1;
  if (R <= mid)
    Insert(l, mid, t << 1, L, R, w);
  else if (L > mid)
    Insert(mid + 1, r, t << 1 | 1, L, R, w);
  else {
    Insert(l, mid, t << 1, L, mid, w);
    Insert(mid + 1, r, t << 1 | 1, mid + 1, r, w);
  }
}
void Solve(int l, int r, int t) {
  tmp[t] = A;
  for (int i = 0; i < V[t].size(); i++) {
    int v = V[t][i];
    A |= (A << v);
    A[v] = 1;
  }
  if (l == r) {
    res |= A;
    return;
  }
  int mid = (l + r) >> 1;
  Solve(l, mid, t << 1);
  Solve(mid + 1, r, t << 1 | 1);
  A = tmp[t];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int l, r, w;
    scanf("%d%d%d", &l, &r, &w);
    Insert(1, n, 1, l, r, w);
  }
  Solve(1, n, 1);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (res[i]) ans++;
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (res[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
