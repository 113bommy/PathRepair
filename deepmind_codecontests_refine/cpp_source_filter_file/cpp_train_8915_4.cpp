#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], f[2][N << 1], Id[2][N], g[2][N], ans;
struct Data {
  int x, Id;
  bool typ;
} A[N << 1];
bool operator<(Data a, Data b) { return a.x < b.x; }
void Add(int x, int y, int z) {
  for (; x <= m; x += x & -x) f[z][x] = max(f[z][x], y);
}
int Ask(int x, int z) {
  int k = 0;
  for (; x; x -= x & -x) k = max(k, f[z][x]);
  return k;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    A[m].x = a[i] - i;
    A[m].typ = 0;
    A[m++].Id = i;
    A[m].x = a[i] - i + 1;
    A[m].typ = 1;
    A[m++].Id = i;
  }
  sort(A, A + m);
  for (int i = 0, j = 0; i < m; i++) {
    j += (i == 0 || A[i].x > A[i - 1].x);
    Id[A[i].typ][A[i].Id] = j;
  }
  for (int i = 1; i <= n; i++) {
    g[0][i] = Ask(Id[0][i], 0) + 1;
    g[1][i] = max(g[1][i], Ask(Id[1][i], 1) + 1);
    if (i < n)
      g[1][i] = Ask(Id[1][i + 1], 0) + 2;
    else
      ans = max(ans, Ask(m, 0) + 1);
    ans = max(ans, max(g[0][i], g[1][i]));
    Add(Id[0][i], g[0][i], 0);
    Add(Id[1][i], g[1][i], 1);
  }
  printf("%d\n", n - ans);
  return 0;
}
