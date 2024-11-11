#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SI = 1 << 21 | 1;
char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
int f, t;
inline void flush() { fwrite(OB, 1, OS - OB, stdout), OS = OB; }
inline void pc(char x) {
  *OS++ = x;
  if (OS == OT) flush();
}
template <class I>
inline void rd(I &x) {
  for (f = 1, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                              IS == IT ? EOF : *IS++)
                            : *IS++);
       c < '0' || c > '9';
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15),
      c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                      IS == IT ? EOF : *IS++)
                    : *IS++))
    ;
  x *= f;
}
inline void rds(char *s, int &x) {
  for (c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++);
       c < 33 || c > 126;
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    ;
  for (x = 0; c >= 33 && c <= 126;
       s[++x] = c, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                                   IS == IT ? EOF : *IS++)
                                 : *IS++))
    ;
  s[x + 1] = '\0';
}
template <class I>
inline void print(I x, char k = '\n') {
  if (!x) pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) ch[++t] = x % 10 + '0', x /= 10;
  while (t) pc(ch[t--]);
  pc(k);
}
inline void prints(string s) {
  int x = s.length();
  while (t < x) pc(s[t++]);
  pc('\n'), t = 0;
}
struct Flush {
  ~Flush() { flush(); }
} flusher;
}  // namespace io
using io::print;
using io::prints;
using io::rd;
using io::rds;
const int N = 2e5 + 7;
int n, a[N], b[N], s, t, p, v[N], d[N];
vector<int> e[N], g, h, A, B;
pair<int, int> o = make_pair(N, 0);
bool dfs1(int x, int f) {
  g.push_back(x);
  if (x == t) return 1;
  for (auto y : e[x])
    if (y != f && dfs1(y, x)) return 1;
  g.pop_back();
  return 0;
}
void dfs2(int x, int f, int d) {
  if (a[x] != b[x]) {
    h.push_back(x), v[x] = 1;
    if (d - 1 == o.first && f != o.second) print(-1), exit(0);
    ;
    if (d - 1 < o.first) o = make_pair(d - 1, f);
  }
  for (auto y : e[x])
    if (y != f) dfs2(y, x, d + 1);
}
void dfs3(int x, int f) {
  if (x != p) A.push_back(a[x]), B.push_back(b[x]);
  for (auto y : e[x])
    if (y != f && v[y]) dfs3(y, x);
}
int dfs4(int x, int f, int d, int t) {
  if (x == t) return d;
  for (auto y : e[x])
    if (y != f) {
      int o = dfs4(y, x, d + 1, t);
      if (o) return o;
    }
  return 0;
}
inline int calc(vector<int> A, vector<int> B) {
  int pos = 0, siz = A.size();
  for (unsigned int i = 0; i < B.size(); i++)
    if (B[i] == A[0]) pos = i;
  if (!pos) return 0;
  for (unsigned int i = 0; i < A.size(); i++)
    if (A[i] != B[(i + pos) % siz]) return 0;
  return pos;
}
inline int S(int x, int y) { return dfs4(x, 0, 0, y); }
inline long long get(int x, int y) {
  int c = calc(A, B);
  return S(s, x) + 1ll * (c - 1) * (A.size() + 1) + 1 + S(y, t);
}
int main() {
  rd(n);
  for (int i = 1; i <= n; i++) rd(a[i]), s = a[i] ? s : i;
  for (int i = 1; i <= n; i++) rd(b[i]), t = b[i] ? t : i;
  for (int i = 1, x, y; i < n; i++)
    rd(x), rd(y), e[x].push_back(y), e[y].push_back(x);
  dfs1(s, 0);
  for (unsigned int i = 1; i < g.size(); i++) swap(a[g[i - 1]], a[g[i]]);
  bool ok = 1;
  for (int i = 1; i <= n; i++) ok &= a[i] == b[i];
  if (ok) return print(0, ' '), print(g.size() - 1), 0;
  dfs2(t, 0, 0), h.push_back(p = o.second), v[p] = 1;
  for (auto x : h)
    for (auto y : e[x])
      if (v[y]) ++d[x];
  vector<int> u;
  for (auto x : h)
    if (d[x] == 1)
      u.push_back(x);
    else if (d[x] != 2)
      print(-1), exit(0);
  ;
  if (u.size() != 2u) print(-1), exit(0);
  ;
  if (u[0] > u[1]) swap(u[0], u[1]);
  dfs3(u[0], 0);
  if (!calc(A, B)) print(-1), exit(0);
  ;
  print(u[0], ' '), print(u[1], ' ');
  long long ans = get(u[0], u[1]);
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  print(max(ans, get(u[1], u[0])));
  return 0;
}
