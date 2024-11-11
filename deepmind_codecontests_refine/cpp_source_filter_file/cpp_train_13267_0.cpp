#include <bits/stdc++.h>
using namespace std;
struct arr {
  int x, y, z;
} a[6005];
int n, sum = 0, mx[3005], fa[3005], sz[3005];
inline bool cmp(arr A, arr B) { return A.z < B.z; }
inline int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
  int x, y, z;
  for (int i = 1; i < n; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
  for (int i = 1; i <= n; i++) scanf("%d", &mx[i]), sum += mx[i];
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i < n; i++) {
    int fx = find(a[i].x);
    int fy = find(a[i].y);
    if (x == y) continue;
    fa[fy] = fx;
    sz[fx] += sz[fy];
    mx[fy] += mx[fy];
    if (sz[fx] > sum - mx[fx]) {
      printf("%d\n", a[i].z);
      return 0;
    }
  }
  printf("%d\n", a[n - 1].z);
  return 0;
}
