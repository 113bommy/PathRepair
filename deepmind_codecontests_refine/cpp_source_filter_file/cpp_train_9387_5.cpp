#include <bits/stdc++.h>
inline int max(int i, int j) { return i > j ? i : j; }
inline int min(int i, int j) { return i < j ? i : j; }
inline int chkmax(int *i, int j) { return *i < j ? *i = j, 1 : 0; }
inline int chkmin(int *i, int j) { return *i > j ? *i = j, 1 : 0; }
inline void swap(int *i, int *j) {
  static int t;
  t = *i, *i = *j, *j = t;
}
int n;
int next[1000050];
char s[1000050];
char t[1000050];
char rs[1000050];
int f[1000050];
int g[1000050];
int h[1000050];
void ext_kmp_init(char *s, char *t, int *f) {
  int i, p = 1, l = f[1];
  for (i = 2; i <= n; ++i)
    if (l >= i + next[i - p + 1])
      f[i] = next[i - p + 1];
    else {
      for (chkmax(&l, i - 1); s[l + 1] == t[l - i + 1]; h[l + 1] = i, ++l)
        ;
      p = i, f[i] = l - i + 1;
    }
}
void ext_kmp(char *s, char *t, int *p, int flag) {
  ext_kmp_init(t, t + 1, next);
  if (flag) memset(h, 0, sizeof(h));
  for (p[1] = 0; s[p[1] + 1] == t[p[1] + 1]; h[p[1]] = 1, ++p[1])
    ;
  ext_kmp_init(s, t + 1, p);
}
void init() {
  int i;
  for (i = 1; i <= n; ++i) rs[i] = s[n + 1 - i];
  ext_kmp(s, t, f, 0);
  ext_kmp(t, rs, g, 1);
  for (i = 1; i <= n; ++i)
    if (h[i]) h[i] = i - h[i] + 1;
}
int main() {
  FILE *fin = stdin;
  FILE *fout = stdout;
  int i, ti = 0, tj = 0;
  fgets(s + 1, sizeof(s), fin);
  int o = strlen(s + 1) - 1;
  fgets(t + 1, sizeof(t), fin);
  n = strlen(s + 1) - 1;
  if (o != n) {
    puts("-1 -1");
    return 0;
  }
  init();
  for (i = 1; i < n && s[i] == t[n + 1 - i]; ++i)
    if (f[i + 1] + h[n - i] + i >= n) ti = i, tj = n - h[n - i] + 1;
  fprintf(fout, "%d %d\n", ti - 1, tj - 1);
  fclose(fin);
  fclose(fout);
  return 0;
}
