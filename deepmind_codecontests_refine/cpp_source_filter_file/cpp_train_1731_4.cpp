#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int f[N], n, m, size[N], x, y, z;
struct Ask {
  int x, y, z;
} A[N];
int cmp(Ask x, Ask y) { return x.z > y.z; }
int find(int x) {
  if (x == f[x]) return x;
  return f[x] = find(f[x]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) f[i] = i, size[i] = 1;
  int ans = 0;
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].z);
  sort(A + 1, A + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    int x = A[i].x, y = A[i].y, z = A[i].z;
    x = find(x);
    y = find(y);
    if (x != y) f[x] = y, size[x] += size[y];
    if (size[x] > 0) size[x]--, ans += z;
  }
  printf("%d\n", ans);
}
