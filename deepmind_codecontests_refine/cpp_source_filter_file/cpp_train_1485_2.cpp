#include <bits/stdc++.h>
using namespace std;
struct IO {
  char buf[(1 << 20)], *p1, *p2;
  char pbuf[(1 << 20)], *pp;
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  inline char gc() {
    return getchar();
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, (1 << 20), stdin);
    return p1 == p2 ? ' ' : *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <class T>
  inline void read(T &x) {
    register double tmp = 1;
    register bool sign = 0;
    x = 0;
    register char ch = gc();
    for (; !(ch >= '0' && ch <= '9'); ch = gc())
      if (ch == '-') sign = 1;
    for (; (ch >= '0' && ch <= '9'); ch = gc()) x = x * 10 + (ch - '0');
    if (ch == '.')
      for (ch = gc(); (ch >= '0' && ch <= '9'); ch = gc())
        tmp /= 10.0, x += tmp * (ch - '0');
    if (sign) x = -x;
  }
  inline void read(char *s) {
    register char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) *s++ = ch;
    *s = 0;
  }
  inline void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  template <class t>
  inline void write(t x) {
    if (x < 0)
      putchar('-'), write(-x);
    else {
      if (x > 9) write(x / 10);
      putchar('0' + x % 10);
    }
  }
} io;
const int mod = 1e9 + 7;
const int mo = 998244353;
const int N = 1e5 + 5;
int n, m, w[N], A[N], B[N], Ans[N], ok[N], top;
vector<pair<int, int> > G[N];
queue<int> q;
int main() {
  io.read(n), io.read(m);
  for (int i = (1); i <= (n); i++) io.read(w[i]);
  for (int i = (1); i <= (m); i++) {
    io.read(A[i]), io.read(B[i]);
    w[A[i]]--, w[B[i]]--;
    G[A[i]].push_back(make_pair(B[i], i));
    G[B[i]].push_back(make_pair(A[i], i));
  }
  for (int i = (1); i <= (n); i++)
    if (w[i] >= 0) q.push(i);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = (0); i <= ((int)G[u].size() - 1); i++) {
      pair<int, int> v = G[u][i];
      if (ok[v.second]) continue;
      ok[v.second] = 1;
      Ans[++top] = v.second;
      w[v.first]++;
      if (!w[v.first]) q.push(v.first);
    }
  }
  if (top < m) return puts("DEAD"), 0;
  puts("ALIVE");
  for (int i = (top); i >= (1); i--) io.write(Ans[i]), putchar(' ');
  return 0;
}
