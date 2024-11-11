#include <bits/stdc++.h>
using namespace std;
const int M = 205;
struct node {
  int id, val;
  bool operator<(const node tmp) const { return val < tmp.val; }
} A[M];
int tmp1[M], tmp2[M], n, m, ans = -1005;
inline void Max(int& x, int y) {
  if (x < y) x = y;
}
void solve(int x, int y) {
  int t1 = 0, t2 = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    if (A[i].id >= x && A[i].id <= y)
      tmp1[t1++] = A[i].val, res += A[i].val;
    else
      tmp2[t2++] = A[i].val;
  }
  int cnt = 0, n1 = 0, n2 = t2 - 1;
  while (cnt < m && n2 >= 0 && n1 < t1) {
    int a = tmp1[n1], b = tmp2[n2];
    if (a >= b) break;
    res += b - a;
    cnt++;
    n1++, n2--;
  }
  Max(ans, res);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i].val), A[i].id = i;
  sort(A + 1, A + n + 1);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++) solve(i, j);
  printf("%d\n", ans);
  return 0;
}
