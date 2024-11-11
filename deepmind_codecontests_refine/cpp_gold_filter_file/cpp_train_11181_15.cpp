#include <bits/stdc++.h>
const int inf = 1 << 20;
const char o = 'a';
char a[3], b[3], s[100600], t[100600], ans[100600] = {0};
int f[30][30] = {0}, n, w, l = 0, l1 = 0, num = 0;
int min(int x, int y) { return x < y ? x : y; }
int main() {
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++) f[i][j] = i ^ j ? inf : 0;
  scanf("%s%s", s, t);
  while (s[l]) l++;
  while (t[l1]) l1++;
  if (l1 ^ l) {
    puts("-1");
    return 0;
  }
  scanf("%d", &n);
  while (n--)
    scanf("%s%s%d", a, b, &w),
        f[a[0] - o][b[0] - o] = min(f[a[0] - o][b[0] - o], w);
  for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  for (int i = 0; i < l; i++) {
    if (s[i] == t[i])
      ans[i] = s[i];
    else {
      ans[i] = 26;
      int m = inf;
      for (int j = 0; j < 26; j++)
        if (f[s[i] - o][j] < m && f[t[i] - o][j] < m &&
            m > f[s[i] - o][j] + f[t[i] - o][j])
          m = f[s[i] - o][j] + f[t[i] - o][j], ans[i] = j;
      if (m == inf) {
        puts("-1");
        return 0;
      }
      ans[i] += o, num += m;
    }
  }
  printf("%d\n%s", num, ans);
  return 0;
}
