#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, Mo = 1000000007;
int cnt = 1, la;
char a[N], s[N];
int fa[N], l[N], ch[N][26], f[N], w[N], g[N], fr[N];
inline int insert(int i) {
  int c = s[i] - 'a';
  while (s[i] != s[i - l[la] - 1]) la = fa[la];
  if (!ch[la][c]) {
    int x = fa[la];
    l[++cnt] = l[la] + 2;
    while (s[i] != s[i - l[x] - 1]) x = fa[x];
    fa[cnt] = x = ch[x][c], ch[la][c] = cnt;
    fr[cnt] = (l[cnt] <= l[x] * 2 ? fr[x] : cnt);
  }
  return la = ch[la][c];
}
int main() {
  scanf("%s", a + 1);
  int n = strlen(a + 1);
  for (int i = 1, l = 1, r = n; i <= n; i += 2)
    s[i] = a[l++], s[i + 1] = a[r--];
  fa[0] = f[0] = 1, l[1] = -1;
  for (int i = 1; i <= n; i++) {
    int x = insert(i);
    while (x > 1) {
      int y = fr[x];
      if (y == x)
        g[x] = f[i - l[x]];
      else
        g[x] = (g[fa[x]] + f[i - l[y]]) % Mo;
      if (~i & 1) f[i] = (f[i] + g[x]) % Mo;
      x = fa[y];
    }
  }
  cout << f[n];
  return 0;
}
