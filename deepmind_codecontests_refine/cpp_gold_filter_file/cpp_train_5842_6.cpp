#include <bits/stdc++.h>
using namespace std;
const int MB = 1 << 21;
struct FastIO {
  char buf[MB + 100], *p, *e;
  int getChar() {
    if (p == e) p = buf, e = buf + fread(buf, 1, MB, stdin);
    return p == e ? EOF : *p++;
  }
  template <typename T>
  FastIO& operator>>(T& x) {
    char c, l;
    for (c = 0; !isdigit(c); c = getChar()) l = c;
    for (x = 0; isdigit(c); c = getChar()) x = x * 10 - '0' + c;
    if (l == '-') x = -x;
    return *this;
  }
} IO;
const int MX = 1000100;
int N;
long long K;
long long A[MX];
const int W = 61;
struct O1Trie {
  int v, c[2];
} T[MX], U[MX];
int I[MX], J[MX];
long long Kth2(long long k) {
  O1Trie *t = T, *u = U;
  for (int i = (1); i <= (N); ++i) I[i] = J[i] = 1;
  t[1].v = N;
  long long res = 0;
  for (int j = (W); j >= (0); --j) {
    memset(u, 0, (N + 1) * sizeof(O1Trie));
    int c = 0;
    for (int i = (1); i <= (N); ++i) {
      int& a = t[I[i]].c[A[i] >> j & 1];
      if (!a) a = ++c;
      ++u[a].v;
    }
    long long v = 0;
    for (int i = (1); i <= (N); ++i) v += u[t[J[i]].c[A[i] >> j & 1]].v;
    if (k > v) res |= 1ll << j, k -= v;
    for (int i = (1); i <= (N); ++i) {
      I[i] = t[I[i]].c[A[i] >> j & 1];
      J[i] = t[J[i]].c[(A[i] ^ res) >> j & 1];
    }
    swap(t, u);
  }
  return res;
}
int main() {
  IO >> N >> K;
  for (int i = (2); i <= (N); ++i) {
    int f;
    long long x;
    IO >> f >> x;
    A[i] = A[f] ^ x;
  }
  printf("%lld\n", Kth2(K));
  return 0;
}
