#include <bits/stdc++.h>
using namespace std;
int n, m, k, sum[100005], nm, ct[100005], nex[400005], wen[400005], hea[100005],
    len, boo[100005], bo[100005], booo[100005], l, r, lr[200005], maxp;
double b[100005], c[100005], maxx;
void add(int x, int y) {
  ++len;
  nex[len] = hea[x];
  wen[len] = y;
  hea[x] = len;
}
void dfs(int x) {
  ++sum[nm];
  boo[x] = nm;
  ct[nm] += bo[x];
  for (int j = hea[x]; j > 0; j = nex[j])
    if (boo[wen[j]] == 0) dfs(wen[j]);
}
void writeln1(int x) {
  boo[x] = 0;
  printf("%d ", x);
  for (int j = hea[x]; j > 0; j = nex[j])
    if (boo[wen[j]]) writeln1(wen[j]);
}
bool check(int x, double y) {
  l = r = 0;
  for (int i = 1; i <= n; i++)
    if (boo[i] == x) {
      c[i] = b[i];
      booo[i] = bo[i];
      if (bo[i]) lr[++r] = i;
    }
  do {
    ++l;
    int u = lr[l];
    for (int i = hea[u]; i > 0; i = nex[i]) {
      int v = wen[i];
      --c[v];
      if (c[v] < y * b[v] && booo[v] == 0) {
        lr[++r] = v;
        booo[v] = 1;
      }
    }
  } while (l < r);
  return l != sum[x];
}
void writeln2(int x, double y) {
  l = r = 0;
  for (int i = 1; i <= n; i++)
    if (boo[i] == x) {
      c[i] = b[i];
      booo[i] = bo[i];
      if (bo[i]) lr[++r] = i, --sum[x];
    }
  do {
    ++l;
    int u = lr[l];
    for (int i = hea[u]; i > 0; i = nex[i]) {
      int v = wen[i];
      --c[v];
      if (c[v] < y * b[v] && booo[v] == 0) {
        --sum[x];
        lr[++r] = v;
        booo[v] = 1;
      }
    }
  } while (l < r);
  printf("%d\n", sum[x]);
  for (int i = 1; i <= n; i++)
    if (boo[i] == x && booo[i] == 0) printf("%d ", i);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    bo[x] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
    b[x] += 1;
    b[y] += 1;
  }
  for (int i = 1; i <= n; i++)
    if (!boo[i]) {
      ++nm;
      dfs(i);
      if (ct[nm] == 0) {
        printf("%d\n", sum[nm]);
        writeln1(i);
        return 0;
      }
    }
  for (int i = 1; i <= nm; i++) {
    double l = 0.0, r = 1.0, mid = 0.5;
    do {
      if (check(i, mid))
        l = mid;
      else
        r = mid;
      mid = (l + r) / 2.0;
    } while (r - l > 0.000000001);
    if (maxx < l) {
      maxx = l;
      maxp = i;
    }
  }
  if (maxx == 0) {
    int i = 1;
    for (; i <= n; i++)
      if (!bo[i]) break;
    printf("1\n%d", i);
    return 0;
  } else
    writeln2(maxp, maxx);
}
