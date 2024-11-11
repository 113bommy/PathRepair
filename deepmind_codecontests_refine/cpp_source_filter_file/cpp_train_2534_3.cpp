#include <bits/stdc++.h>
using namespace std;
const int maxn = 1501;
struct arr {
  int x, y, z;
} d[maxn];
int a[maxn * 2][2], b[maxn], f[maxn], v[maxn];
int n, s;
void add(int i, int j) {
  a[++s][0] = b[i];
  b[i] = s;
  a[s][1] = j;
}
void dfs(int k) {
  int i, j;
  f[k] = 1;
  for (i = b[k]; i; i = a[i][0]) {
    j = a[i][1];
    if (!f[j]) {
      dfs(j);
      f[k] += f[j];
    }
  }
}
bool cmp(arr i, arr j) {
  return ((long long)i.x * j.y - (long long)i.y * j.x) > 0;
}
void dfs(int k, int l, int r) {
  int i, j = r, s;
  if (l > r) return;
  for (i = l; i < r; i++)
    if (d[i].y < d[j].y) j = i;
  v[d[j].z] = k;
  if (l == r) return;
  swap(d[j], d[l]);
  for (i = l + 1; i <= r; i++) d[i].x -= d[l].x, d[i].y -= d[l].y;
  l++;
  sort(d + l + 1, d + r + 1, cmp);
  for (i = b[k]; i; i = a[i][0]) {
    j = a[i][1];
    if (f[j] < f[k]) {
      dfs(j, l, l + f[j] - 1);
      l += f[j];
    }
  }
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (k = 1; k < n; k++) {
    scanf("%d%d", &i, &j);
    add(i, j);
    add(j, i);
  }
  dfs(1);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &d[i].x, &d[i].y);
    d[i].z = i;
  }
  dfs(1, 1, n);
  for (i = 1; i <= n; i++) printf("%d ", v[i]);
  printf("\n");
  return 0;
}
