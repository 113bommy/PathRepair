#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, s, an;
int a[300010], b[300010], c[300010], d[300010], flag[300010], f[300010],
    g[300010][3], fa[300010], ff[300010 * 2];
set<pair<int, int> > S;
priority_queue<int> q;
inline void prepare() {
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), d[++s] = a[i];
  for (i = 1; i <= n; i++) scanf("%d", &b[i]), d[++s] = b[i];
  for (i = 1; i <= n; i++) scanf("%d", &c[i]), d[++s] = c[i];
  sort(d + 1, d + s + 1);
  for (i = 1; i <= s; i++)
    if (i == 1 || d[i] > d[m]) d[++m] = d[i];
  for (i = 1; i <= n; i++) a[i] = lower_bound(d + 1, d + m + 1, a[i]) - d;
  for (i = 1; i <= n; i++) b[i] = lower_bound(d + 1, d + m + 1, b[i]) - d;
  for (i = 1; i <= n; i++) c[i] = lower_bound(d + 1, d + m + 1, c[i]) - d;
  for (i = 1; i <= n; i++)
    if (flag[a[i]] != 1) flag[a[i]] = 1, fa[i] = 1;
  for (i = 1; i <= n; i++)
    if (flag[b[i]] != 2) flag[b[i]] = 2, g[b[i]][1] = i;
  for (i = 1; i <= n; i++)
    if (flag[c[i]] != 3) flag[c[i]] = 3, g[c[i]][2] = i;
}
inline void dian(int x) {
  if (!flag[x]) s++;
  flag[x]++;
}
inline void work1() {
  s = 0;
  for (i = 1; i <= m; i++) flag[i] = 0;
  for (i = 1; i <= n; i++) dian(a[i]);
  for (i = 1; i <= n; i++) dian(b[i]);
  for (i = 0; i <= n; i++) f[i] = 300010;
  for (j = 1; j <= n && s < m; j++) dian(c[j]);
  for (i = n; i >= 0; i--) {
    f[i] = j - 1;
    if (!i) break;
    if (!(--flag[b[i]])) s--;
    for (; j <= n && s < m; j++) dian(c[j]);
    if (s < m) break;
  }
}
inline void Into(int x, int y) {
  S.insert(make_pair(x, y));
  q.push(-x - y);
}
inline void Do(int r, int k) {
  set<pair<int, int> >::iterator A = S.lower_bound(make_pair(r + 1, -1));
  if (A != S.end() && A->second >= k) return;
  int B = -1, C, F = 0;
  for (;;) {
    A = S.lower_bound(make_pair(r + 1, -1));
    A--;
    if (A->second == k) F = 1;
    if (A->second >= k) break;
    if (B < 0) C = A->second;
    B = A->first;
    ff[A->first + A->second]++;
    S.erase(A);
  }
  if (B < 0) return;
  A = S.lower_bound(make_pair(r + 1, -1));
  if (r <= n && !(A != S.end() && A->first == r + 1)) Into(r + 1, C);
  if (!F) Into(B, k);
}
inline void work2() {
  S.insert(make_pair(-1, 300010 + 1));
  for (i = 0; i <= n; i++)
    if (!i || f[i] != f[i - 1]) Into(i, f[i]);
  for (i = n; i >= 0; i--) {
    int res;
    for (; ff[res = -q.top()];) ff[res]--, q.pop();
    an = min(an, i + res);
    if (!i) break;
    int A = a[i];
    if (fa[i]) {
      int B = g[A][1], C = g[A][2];
      if (!B && !C) return;
      if (!B)
        Do(n, C);
      else if (!C)
        Do(B - 1, 300010);
      else
        Do(B - 1, C);
    }
  }
}
int main() {
  scanf("%d", &n);
  prepare();
  work1();
  an = n * 3, work2();
  printf("%d\n", an);
  return 0;
}
