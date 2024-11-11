#include <bits/stdc++.h>
using namespace std;
const int M = 400005;
int read() {
  int x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
int n, m, ans;
char s[M];
struct automaton {
  int cnt, last, len[M], fa[M], ch[M][26];
  int siz[M], tr[M], c[M], A[M];
  long long ans;
  automaton() { cnt = last = 1; }
  void add(int c, int i) {
    int p = last, np = last = ++cnt;
    len[np] = len[p] + 1;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p)
      fa[np] = 1;
    else {
      int q = ch[p][c];
      if (len[q] == len[p] + 1)
        fa[np] = q;
      else {
        int nq = ++cnt;
        fa[nq] = fa[q];
        memcpy(ch[nq], ch[q], sizeof ch[q]);
        len[nq] = len[p] + 1;
        fa[q] = fa[np] = nq;
        for (; p && ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
      }
    }
    siz[np] = 1;
    tr[i] = np;
  }
  void solve() {
    for (int i = 1; i <= cnt; i++) c[len[i]]++;
    for (int i = 1; i <= n; i++) c[i] += c[i - 1];
    for (int i = 1; i <= cnt; i++) A[c[len[i]]--] = i;
    for (int i = cnt; i >= 1; i--) {
      siz[fa[A[i]]] += siz[A[i]];
      ans = max(ans, 1ll * siz[A[i]] * len[i]);
    }
    printf("%lld\n", ans);
  }
} Sam;
int main() {
  n = read();
  scanf("%s", s);
  for (int i = 0; i < n; i++) Sam.add(s[i] - 'a', i);
  scanf("%s", s);
  for (int i = 0; i < n; i++)
    if (s[i] == '1') Sam.siz[Sam.tr[i]] = 0;
  Sam.solve();
}
