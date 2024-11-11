#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char tempt = getchar();
  long long x = 0, f = 0;
  while (tempt < '0' || tempt > '9') f |= tempt == '-', tempt = getchar();
  while (tempt >= '0' && tempt <= '9')
    x = x * 10 + tempt - '0', tempt = getchar();
  return f ? -x : x;
}
void write(register long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10)
    putchar(x + '0');
  else {
    write(x / 10);
    putchar(x % 10 + '0');
  }
}
inline void print(const register long long x, const register char c = '\n') {
  write(x);
  putchar(c);
}
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(long long &x) { x = read(); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const long long &x) { cout << x; }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
long long qmi(long long m, long long k, long long p) {
  long long res = 1 % p, t = m;
  while (k) {
    if (k & 1) res = res * t % p;
    t = t * t % p;
    k >>= 1;
  }
  return res;
}
inline long long qmi(long long m, long long k) {
  long long res = 1, t = m;
  while (k) {
    if (k & 1) res = res * t;
    t = t * t;
    k >>= 1;
  }
  return res;
}
inline bool ou(long long x) { return x % 2 == 0; }
const long long N = 60;
long long n;
string s[N];
long long f[N][N][N][N];
long long dfs(long long len, long long a, long long b, long long c) {
  if (len == 1) return 1;
  if (f[len][a][b][c]) return 1;
  if (s[b][0] == s[c][0] || s[b][1] == s[c][1])
    if (dfs(len - 1, len - 1, a, c)) return 1;
  if (len > 3 && (s[len - 3][1] == s[c][1] || s[len - 3][0] == s[c][0]))
    if (dfs(len - 1, c, a, b)) return 1;
  f[len][a][b][c] = 1;
  return 0;
}
int32_t main() {
  R(n);
  for (register long long i = 1; i <= n; i++) cin >> s[i];
  if (dfs(n, n - 2, n - 1, n))
    W("YES");
  else
    W("NO");
}
