#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
template <class T>
inline void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x / 10) write(x / 10);
  putchar('0' + x % 10);
}
template <class T>
inline void Max(T &x, T y) {
  if (y > x) x = y;
}
template <class T>
inline void Min(T &x, T y) {
  if (y < x) x = y;
}
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
int ch[N][26], pre[N], mxl[N], last = 1, cnt = 1, len, sz[N];
char s[N];
inline void Extend(int c) {
  int p = last, np = ++cnt;
  last = np;
  mxl[np] = mxl[p] + 1;
  sz[np] = 1;
  for (; p && !ch[p][c]; p = pre[p]) ch[p][c] = np;
  if (!p) {
    pre[np] = 1;
    return;
  }
  int q = ch[p][c], nq = ++cnt;
  if (mxl[q] == mxl[p] + 1) {
    pre[np] = q;
    --cnt;
    return;
  }
  memcpy(ch[nq], ch[q], sizeof(ch[q]));
  mxl[nq] = mxl[p] + 1, pre[nq] = pre[q], pre[q] = pre[np] = nq;
  for (; ch[p][c] == q; p = pre[p]) ch[p][c] = nq;
}
int tt[N], qq[N];
long long ans;
inline void init() {
  for (int i = 1; i <= cnt; i++) tt[mxl[i]]++;
  for (int i = 1; i <= cnt; i++) tt[i] += tt[i - 1];
  for (int i = 1; i <= cnt; i++) qq[tt[mxl[i]]--] = i;
  for (int i = cnt; i >= 1; i--) sz[pre[qq[i]]] += sz[qq[i]];
  for (int i = 2; i <= cnt; i++)
    ans += 1ll * sz[i] * (sz[i] + 1) * (mxl[i] - mxl[pre[i]]) / 2;
  write(ans);
}
int main() {
  scanf("%s", s + 1);
  len = strlen(s + 1);
  for (int i = 1; i <= len; i++) Extend(s[i] - 'a');
  init();
  return 0;
}
