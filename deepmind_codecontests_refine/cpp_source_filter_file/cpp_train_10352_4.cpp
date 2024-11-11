#include <bits/stdc++.h>
using namespace std;
namespace my_useful_tools {
const int INF = 0x3f3f3f3f;
inline void pc(char c) { putchar(c); }
template <class T>
inline T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T>
inline void W(T p) {
  if (p < 0) pc('-'), p = -p;
  if (p / 10 != 0) W(p / 10);
  pc('0' + p % 10);
}
template <class T>
inline void Wn(T p) {
  W(p), puts("");
}
template <class T>
inline void W(T a, T b) {
  W(a), pc(' '), W(b);
}
template <class T>
inline void Wn(T a, T b) {
  W(a), pc(' '), Wn(b);
}
template <class T>
inline void W(T a, T b, T c) {
  W(a), pc(' '), W(b), pc(' '), W(c);
}
inline char gchar() {
  char ret = getchar();
  for (; ret == '\n' || ret == '\r' || ret == ' '; ret = getchar())
    ;
  return ret;
}
template <class T>
inline void fr(T& ret) {
  char c = ' ';
  int flag = 1;
  for (c = getchar(); c != '-' && !('0' <= c && c <= '9'); c = getchar())
    ;
  if (c == '-')
    flag = -1, ret = 0;
  else
    ret = c - '0';
  for (c = getchar(); '0' <= c && c <= '9'; c = getchar())
    ret = ret * 10 + c - '0';
  ret = ret * flag;
}
inline int fr() {
  int x;
  fr(x);
  return x;
}
template <class T>
inline void fr(T& a, T& b) {
  fr(a), fr(b);
}
template <class T>
inline void fr(T& a, T& b, T& c) {
  fr(a), fr(b), fr(c);
}
template <class T>
inline T fast_pow(T base, T index, T mod = 2147483647, T ret = 1) {
  for (; index; index >>= 1, base = base * base % mod)
    if (index & 1) ret = ret * base % mod;
  return ret;
}
const int maxv = 100, maxe = 100;
struct Edge {
  int edge, head[maxv], to[maxe], next[maxe];
  Edge() {
    edge = 0;
    memset(head, -1, sizeof head);
  }
  void addedge(int u, int v) {
    to[edge] = v, next[edge] = head[u];
    head[u] = edge++;
  }
};
};  // namespace my_useful_tools
using namespace my_useful_tools;
const int maxn = 20 + 1;
int status[maxn], n;
long long num[maxn][2];
vector<int> build(int n) {
  if (n == 0) {
    return vector<int>(1, fr());
  } else {
    vector<int> l = build(n - 1), r = build(n - 1);
    for (int x = 0; x < 2; swap(l, r), ++x) {
      for (int i = 0, j = 0; i < (1 << (n - 1)); ++i) {
        while (j < (1 << (n - 1)) && l[i] > r[j]) ++j;
        num[n][x] += j;
      }
    }
    vector<int> ret(1 << n);
    merge(l.begin(), l.end(), r.begin(), r.end(), ret.begin());
    return ret;
  }
}
int main() {
  build(n = fr());
  for (int m = fr(), q; m--;) {
    fr(q);
    for (int j = 0; j < q; ++j) status[j] ^= 1;
    long long res = 0;
    for (int j = 0; j < n; ++j) res += num[j][status[j]];
    Wn(res);
  }
  return 0;
}
