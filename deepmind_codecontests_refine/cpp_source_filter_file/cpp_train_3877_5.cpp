#include <bits/stdc++.h>
namespace IPT {
const int L = 1 << 21;
char buf[L], *front = buf, *end = buf;
char GetChar() {
  if (front == end) end = buf + fread(front = buf, 1, L, stdin);
  return (front == end) ? -1 : *(front++);
}
template <typename T>
inline void qr(T &x) {
  char ch = GetChar(), lst = 0;
  x = 0;
  while (!isdigit(ch)) lst = ch, ch = GetChar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = GetChar();
  if (lst == '-') x = -x;
}
template <typename T>
void qra(T *const __ary, int __n) {
  for (int i = 0; i < __n; ++i) qr(__ary[i]);
}
template <typename T>
int qrs(T *p) {
  T *beg = p;
  do *p = GetChar();
  while ((!isalnum(*p)) && (*p != '?'));
  do *(++p) = GetChar();
  while ((isalnum(*p)) || (*p == '?'));
  *p = 0;
  return p - beg;
}
template <typename T>
void qrdb(T &x) {
  char ch = GetChar(), lst = 0;
  x = 0;
  while (!isdigit(ch)) lst = ch, ch = GetChar();
  while (isdigit(ch)) {
    x = x * 10 + (ch - '0');
    ch = GetChar();
  }
  if (ch == '.') {
    ch = GetChar();
    for (double t = 0.1; isdigit(ch); t *= 0.1) {
      x += (t * (ch - '0'));
      ch = GetChar();
    }
  }
  if (lst == '-') x = -x;
}
}  // namespace IPT
namespace OPT {
const int L = 30;
char buf[L];
template <typename T>
inline void qw(T x, const char aft = 0) {
  if (x < 0) {
    x = -x, putchar('-');
  }
  int top = 0;
  do {
    buf[++top] = static_cast<char>(x % 10 + '0');
  } while (x /= 10);
  while (top) putchar(buf[top--]);
  if (aft) putchar(aft);
}
template <typename T>
void qwa(T *const __ary, int __n, const char e1, const char e2) {
  int __dn = __n - 1;
  for (int i = 0; i < __dn; ++i) qw(__ary[i], e1);
  qw(__ary[__dn], e2);
}
template <typename T>
void qws(T *p, const int __n, const char ed) {
  for (int i = 0; i < __n; ++i) putchar(p[i]);
  if (ed) putchar(ed);
}
template <typename T>
void qws(T *p, const char ed) {
  while (*p) putchar(*p++);
  if (ed) putchar(ed);
}
}  // namespace OPT
using IPT::qr;
using IPT::qra;
using IPT::qrdb;
using IPT::qrs;
using OPT::qw;
using OPT::qwa;
using OPT::qws;
namespace Fusu {
void Main();
}
int main() {
  ;
  Fusu::Main();
  return 0;
}
namespace Fusu {
const int maxt = 14;
const int maxh = 1005;
const int maxn = 400005;
const int maxs = (1 << maxt) + 5;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
void Init();
void Calc();
void Build();
void Main() {
  Init();
  Build();
  Calc();
}
int n;
char s[maxn];
struct Node {
  long long v;
  Node *trans[maxt], *fail;
  std::vector<Node *> fson;
};
Node Mem[maxn], *pool = Mem + 1, *rot = Mem;
void Init() {
  qr(n);
  for (int i = 1, len; i <= n; ++i) {
    len = qrs(s + 1);
    auto u = rot;
    for (int j = 1, k = s[j] - 'a'; j <= len; k = s[++j] - 'a') {
      u = u->trans[k] ? u->trans[k] : (u->trans[k] = pool++);
    }
    qr(len);
    u->v += len;
  }
}
void dfs(Node *const u) {
  for (auto v : u->fson) {
    v->v += u->v;
    dfs(v);
  }
}
std::queue<Node *> Q;
void Build() {
  for (auto &v : rot->trans)
    if (v != nullptr) {
      v->fail = rot;
      Q.push(v);
    } else {
      v = rot;
    }
  for (Node *u, *v; !Q.empty(); Q.pop()) {
    u = Q.front();
    v = u->fail;
    v->fson.push_back(u);
    for (int i = 0; i < maxt; ++i)
      if (u->trans[i]) {
        u->trans[i]->fail = v->trans[i];
        Q.push(u->trans[i]);
      } else {
        u->trans[i] = v->trans[i];
      }
  }
  dfs(rot);
}
std::vector<std::pair<int, int> > rng;
long long f[maxh][maxs];
std::vector<int> sta[maxt];
inline int countbit(int x) {
  int ret = 0;
  while (x) {
    ++ret;
    x &= x - 1;
  }
  return ret;
}
void Calc() {
  int nn = qrs(s + 1);
  int tn = pool - Mem;
  rng.push_back({0, 0});
  int jk = 1;
  for (int i = 1; i <= nn; ++i)
    if (s[i] == '?') {
      rng.push_back({jk, i});
      jk = i + 1;
    }
  n = rng.size();
  int upc = (1 << 14) - 1;
  for (int i = 0; i <= upc; ++i) {
    sta[countbit(i)].push_back(i);
  }
  memset(f, -0x3f, sizeof f);
  f[0][0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < tn; ++j) {
      long long tv = 0;
      auto u = Mem + j;
      for (int k = rng[i].first; k < rng[i].second; ++k) {
        u = u->trans[s[k] - 'a'];
        tv += u->v;
      }
      for (auto s : sta[i - 1]) {
        for (int k = 0, ss = 1 << k; k < maxt; ss = 1 << ++k)
          if ((s & ss) == 0) {
            int pp = u->trans[k] - Mem;
            f[pp][s | ss] =
                std::max(f[pp][s | ss], f[j][s] + tv + u->trans[k]->v);
          }
      }
    }
  }
  long long ans = -INF;
  for (int i = 0; i < tn; ++i) {
    int tv = 0;
    auto u = Mem + i;
    for (int k = jk; k <= nn; ++k) {
      u = u->trans[s[k] - 'a'];
      tv += u->v;
    }
    for (auto s : sta[n - 1]) {
      ans = std::max(ans, f[i][s] + tv);
    }
  }
  qw(ans, '\n');
}
}  // namespace Fusu
