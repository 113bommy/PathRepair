#include <bits/stdc++.h>
using namespace std;
struct rec {
  int b, f;
} bj[1010];
int n, m, k, i, j, numkey, key, len;
int a[1010], b[1010], f[1010], tf[1010], head[1010], wh1[1010], wh2[1010],
    bl[1010], tbl[1010];
bool used[1010];
char name1[1010][15], name2[1010][15];
int find(int a) {
  if (f[a] == a) return a;
  return f[a] = find(f[a]);
}
void deal() {
  int i, p, t, t1, t2;
  for (i = 1; i <= n; i++) f[i] = i;
  while (true) {
    p = 0;
    for (i = 1; i <= m; i++)
      if (!used[i]) {
        t = find(bl[i]);
        t1 = find(a[i]);
        t2 = find(b[i]);
        if (t1 > t2) swap(t1, t2);
        if (t == t1 || t == t2) {
          f[t2] = t1;
          p = i;
          used[i] = true;
        }
      }
    if (!p) return;
  }
}
bool equal(int a, int b) {
  int len1 = strlen(name1[a]), len2 = strlen(name2[b]), i;
  if (len1 != len2) return 0;
  for (i = 0; i < len1; i++)
    if (name1[a][i] != name2[b][i]) return 0;
  return 1;
}
bool equal() {
  int i;
  for (i = 1; i <= n; i++)
    if (tf[i] != f[i]) return 0;
  for (i = 1; i <= k; i++)
    for (j = 1; j <= k; j++) {
      if (equal(i, j)) {
        if (tf[wh1[i]] != find(wh2[j])) return 0;
      }
    }
  for (i = 1; i <= m; i++)
    if (tf[tbl[i]] != find(bl[i])) return 0;
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= m; i++) scanf("%d%d", &a[i], &b[i]);
  for (i = 1; i <= k; i++) {
    scanf("\n%s%d%d\n", name1[i], &wh1[i], &numkey);
    for (j = 1; j <= numkey; j++) {
      scanf("%d", &key);
      bl[key] = wh1[i];
    }
  }
  deal();
  for (i = 1; i <= n; i++) f[i] = find(f[i]);
  memcpy(tf, f, sizeof(tf));
  memcpy(tbl, bl, sizeof(bl));
  memset(used, 0, sizeof(used));
  for (i = 1; i <= k; i++) {
    scanf("\n%s%d%d\n", name2[i], &wh2[i], &numkey);
    for (j = 1; j <= numkey; j++) {
      scanf("%d", &key);
      bl[key] = wh2[i];
    }
  }
  deal();
  if (equal())
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
