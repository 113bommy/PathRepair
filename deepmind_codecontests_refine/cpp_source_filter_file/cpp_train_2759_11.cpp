#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000050;
int Lyndom(char *buf, int n, int *pos) {
  int r = 0;
  for (int i = 0, j, k; i < n;) {
    for (k = i, j = i + 1; j < n and buf[k] <= buf[j]; ++j)
      buf[k] < buf[j] ? k = i : ++k;
    for (pos[++r] = i; i <= k; i += j - k)
      ;
  }
  return r;
}
void Z_function(char *buf, int n, int *z) {
  z[0] = n;
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    z[i] = i > r ? 0 : min(r - i + 1, z[i - l]);
    while (i + z[i] < n and buf[z[i]] == buf[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}
char buf[maxn], ans[maxn], rans[maxn];
char *cur = ans, *rcur = rans;
int z[maxn], pos[maxn], n, k, m;
void add(const char *src, int l, char *&c) {
  copy(src, src + l, c);
  c += l;
}
void add_suf(int l, char *c) {
  int w = z[2 * n + 1 - l];
  add((w >= l || buf[w] > buf[l - 1 - w]) ? buf + 2 * n + 1 - l : buf, l, c);
}
int l, best;
int main() {
  scanf("%s", buf);
  n = strlen(buf);
  scanf("%d", &k);
  copy(buf, buf + n, buf + n + 1);
  reverse_copy(buf + n + 1, buf + 2 * n + 1, buf);
  m = Lyndom(buf, n, pos);
  Z_function(buf, 2 * n + 1, z);
  l = n;
  if (k > 2)
    for (; m; l = pos[m--])
      if (buf[pos[m]] != buf[l - 1]) break;
  if (l != n) k--;
  add(buf + n + 1, n - l, cur);
  for (; m > 1 and k > 2; l = pos[m--], k--) add(buf + pos[m], l - pos[m], cur);
  if (k == 1 or m <= 1) {
    add_suf(l, cur);
  } else {
    add(ans, n - l, rcur);
    add(buf + pos[m], l - pos[m], cur);
    add_suf(pos[m], cur);
    add(buf + pos[m - 1], l - pos[m - 1], rcur);
    add_suf(pos[m - 1], rcur);
    if (strcmp(rans, ans) < 0) copy(rans, rans + n, ans);
    best = 1;
    for (int i = 2; i < l; i++) {
      int p = z[2 * n + 1 - i];
      if (p < i - best) {
        if (buf[p] < buf[i - p - 1]) best = i;
      } else {
        p = z[i - best];
        if (p <= best and buf[i - best + p] < buf[p]) best = i;
      }
    }
    rcur = rans + l;
    add(buf + 2 * n + 1 - l, l - best, rcur);
    add(buf, best, rcur);
    if (strcmp(rans, ans) < 0) copy(rans, rans + n, ans);
  }
  puts(ans);
  return 0;
}
