#include <bits/stdc++.h>
using namespace std;
template <class F, class T>
T convert(F a, int p = -1) {
  stringstream ss;
  if (p >= 0) ss << fixed << setprecision(p);
  ss << a;
  T r;
  ss >> r;
  return r;
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T cube(T x) {
  return x * x * x;
}
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return s == 0 ? 0 : cntbit(s >> 1) + (s & 1);
}
const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;
char gc() {
  if (rsz <= 0) {
    ptr = 0;
    rsz = (int)fread(bf, 1, bfsz, stdin);
    if (rsz <= 0) return EOF;
  }
  --rsz;
  return bf[ptr++];
}
void ga(char &c) {
  c = EOF;
  while (!isalpha(c)) c = gc();
}
int gs(char s[]) {
  int l = 0;
  char c = gc();
  while (isspace(c)) c = gc();
  while (c != EOF && !isspace(c)) {
    s[l++] = c;
    c = gc();
  }
  s[l] = '\0';
  return l;
}
template <class T>
bool gi(T &v) {
  v = 0;
  char c = gc();
  while (c != EOF && c != '-' && !isdigit(c)) c = gc();
  if (c == EOF) return false;
  bool neg = c == '-';
  if (neg) c = gc();
  while (isdigit(c)) {
    v = v * 10 + c - '0';
    c = gc();
  }
  if (neg) v = -v;
  return true;
}
int a[22][20005];
int n, k;
int main() {
  cin >> n >> k;
  for (int i = (1); i <= (k); ++i) {
    a[i][n - 1] = n;
    a[i][n] = n;
  }
  int T = 1, run = 0;
  while (n - T - 1 >= 1) {
    int u = max(n - T - T, 1), v = n - T - 1;
    for (int i = (1); i <= (run); ++i)
      for (int j = (u); j <= (v); ++j) a[i][j] = a[i][j + T];
    for (int i = (u); i <= (v); ++i) a[run + 1][i] = v + 1;
    for (int i = (run + 2); i <= (k); ++i)
      for (int j = (u); j <= (v); ++j) a[i][j] = n;
    T <<= 1;
    run++;
  }
  for (int i = (1); i <= (k); ++i) {
    for (int j = (1); j <= (n); ++j)
      printf("%d%c", a[i][j], j == n ? '\n' : ' ');
  }
  return 0;
}
