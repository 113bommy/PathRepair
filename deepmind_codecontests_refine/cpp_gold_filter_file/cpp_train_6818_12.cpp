#include <bits/stdc++.h>
int cmp(const void* a, const void* b) { return *(int*)b - *(int*)a; }
int sz[100010], st[100010], px[100010], n, dy[100010], la[100010], dp[100010];
int find(int x) {
  int l = -1, r = n;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    if (st[m] < x)
      l = m;
    else
      r = m - 1;
  }
  return l;
}
void insert(int t, int u, int x) {
  st[t + 1] = x;
  dy[t + 1] = u;
  dp[u] = t + 1;
  if (t >= 0) la[u] = dy[t];
}
void insert(int u, int x) {
  int t = find(x);
  insert(t, u, x);
}
bool bk[100010];
int main() {
  int m;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &sz[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%d", &px[i]);
  for (int i = 0; i <= n; i++) st[i] = 1999999999;
  qsort(px, m, sizeof(int), cmp);
  for (int i = 1; i <= n; i++) {
    if (sz[i] != -1)
      insert(i, sz[i]);
    else {
      for (int j = 0, t = n; j < m; j++) {
        while (t >= 0 && st[t] >= px[j]) t -= 1;
        insert(t, i, px[j]);
      }
    }
  }
  int s = 0;
  while (st[s + 1] < 1999999999) s += 1;
  int u = dy[s], lz = 1999999999;
  while (s >= 0) {
    if (sz[u] == -1) {
      int z = 0, t = u - 1;
      while (z < m && (px[z] >= lz || bk[z])) z += 1;
      lz = px[z];
      sz[u] = lz;
      bk[z] = true;
      while (t > 0) {
        if (sz[t] != -1 && sz[t] < lz && dp[t] == s - 1) break;
        t -= 1;
      }
      if (t == 0) {
        t = u - 1;
        while (t > 0 && sz[t] != -1) t--;
      }
      u = t;
    } else {
      lz = sz[u];
      u = la[u];
    }
    s -= 1;
  }
  for (int i = 1, t = 0; i <= n; i++) {
    if (sz[i] == -1) {
      while (bk[t]) t++;
      sz[i] = px[t];
      bk[t] = true;
    }
    printf("%d ", sz[i]);
  }
  return 0;
}
