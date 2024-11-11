#include <bits/stdc++.h>
using namespace std;
namespace fast_io {
char buf[1 << 12], *p1 = buf, *p2 = buf, sr[1 << 23], z[23], nc;
int C = -1, Z = 0, Bi = 0, ny;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0;
  ny = 1;
  while (nc = gc(), (nc < 48 || nc > 57) && nc != EOF)
    if (nc == 45) ny = -1;
  Bi = 1;
  if (nc < 0) return nc;
  x = nc - 48;
  while (nc = gc(), 47 < nc && nc < 58 && nc != EOF)
    x = (x << 3) + (x << 1) + (nc ^ 48), Bi++;
  return x * ny;
}
inline double gf() {
  int a = read(), y = ny, b = (nc != '.') ? 0 : read();
  return (b ? a + (double)b / pow(10, Bi) * y : a);
}
inline int gs(char *s) {
  char c, *t = s;
  while (c = gc(), c <= 32)
    ;
  *s++ = c;
  while (c = gc(), c > 32) *s++ = c;
  return s - t;
}
inline void ot() {
  fwrite(sr, 1, C + 1, stdout);
  C = -1;
}
inline void flush() {
  if (C > 1 << 22) ot();
}
template <typename T>
inline void write(T x, char t) {
  int y = 0;
  if (x < 0) y = 1, x = -x;
  while (z[++Z] = x % 10 + 48, x /= 10)
    ;
  if (y) z[++Z] = '-';
  while (sr[++C] = z[Z], --Z)
    ;
  sr[++C] = t;
  flush();
}
inline void write(char *s) {
  int l = strlen(s);
  for (int i = 0; i < l; i++) sr[++C] = *s++;
  sr[++C] = '\n';
  flush();
}
};  // namespace fast_io
using namespace fast_io;
const int N = 3e3 + 5;
int r, c, n, k, p[N], q[N], t[N], v[N];
long long ans;
pair<int, int> a[N];
vector<pair<int, int> > vr[N], vc[N];
inline long long ask(int i, int j, int k) {
  long long res = 1ll * (t[k] - j + 1) * (a[k].second - a[p[k]].second) *
                  (c - a[v[k]].second + 1);
  return t[k] = j - 1, res;
}
int main() {
  r = read(), c = read(), n = read(), k = read();
  for (int i = 1, x, y; i <= n; i++)
    x = read(), y = read(), a[i] = {x, y}, vr[x].push_back({y, i}),
    vc[y].push_back({x, i});
  for (int i = 1; i <= r; i++) sort(vr[i].begin(), vr[i].end());
  for (int i = 1; i <= c; i++) sort(vc[i].begin(), vc[i].end());
  a[n + 1] = {r + 1, c + 1};
  for (int i = 1; i <= r; i++) {
    int o = 0;
    for (int j = 1; j <= c; j++)
      for (auto x : vc[j])
        if (x.first >= i)
          q[o] = x.second, p[x.second] = o, o = x.second, t[o] = r, v[o] = 0;
    q[o] = q[n + 1] = v[n + 1] = n + 1, t[n + 1] = r, o = 0;
    for (int j = 1; j <= k; j++) o = q[o];
    for (int j = q[0]; j ^ (n + 1); j = q[j], o = q[o]) v[j] = o;
    for (int j = r; j >= i; j--)
      for (auto x : vr[j]) {
        ans += ask(i, j, q[x.second]), o = x.second;
        for (int l = 1; o && l <= k; l++, o = p[o]) ans += ask(i, j, o);
        q[p[x.second]] = q[x.second], p[q[x.second]] = p[x.second];
        int w = o = q[o];
        for (int l = 1; l < k; l++) w = q[w];
        while (o ^ q[x.second]) v[o] = w, o = q[o], w = q[w];
      }
  }
  write(ans, '\n');
  return ot(), 0;
}
