#include <bits/stdc++.h>
using namespace std;
struct Scanner {
  bool hasNext = 1;
  bool hasRead = 1;
  int nextInt() {
    hasRead = 0;
    int res = 0;
    char flag = 1, ch = getchar();
    while (ch != EOF && !isdigit(ch)) {
      hasRead = 1;
      flag = (ch == '-') ? -flag : flag;
      ch = getchar();
    }
    while (ch != EOF && isdigit(ch)) {
      hasRead = 1;
      res = res * 10 + (ch - '0');
      ch = getchar();
    }
    if (ch == EOF) hasNext = 0;
    return res * flag;
  }
  long long nextLL() {
    hasRead = 0;
    long long res = 0;
    char flag = 1, ch = getchar();
    while (ch != EOF && !isdigit(ch)) {
      hasRead = 1;
      flag = (ch == '-') ? -flag : flag;
      ch = getchar();
    }
    while (ch != EOF && isdigit(ch)) {
      hasRead = 1;
      res = res * 10 + (ch - '0');
      ch = getchar();
    }
    if (ch == EOF) hasNext = 0;
    return res * flag;
  }
  char nextChar() {
    hasRead = 0;
    char ch = getchar();
    while (ch != EOF && isspace(ch)) {
      hasRead = 1;
      ch = getchar();
    }
    if (ch == EOF) hasNext = 0;
    return ch;
  }
  int nextString(char *str) {
    hasRead = 0;
    int len = 0;
    char ch = getchar();
    while (ch != EOF && isspace(ch)) {
      hasRead = 1;
      ch = getchar();
    }
    while (ch != EOF && !isspace(ch)) {
      hasRead = 1;
      str[++len] = ch;
      ch = getchar();
    }
    str[len + 1] = 0;
    if (ch == EOF) hasNext = 0;
    return len;
  }
} sc;
long long rd() {
  long long x = sc.nextLL();
  return x;
}
void rd(int &x) { x = sc.nextInt(); }
void rd(long long &x) { x = sc.nextLL(); }
void rd(char &x) { x = sc.nextChar(); }
void rd(char *x) { sc.nextString(x); }
template <typename T1, typename T2>
void rd(pair<T1, T2> &x) {
  rd(x.first);
  rd(x.second);
}
template <typename T>
void rd(T *x, int n) {
  for (int i = 1; i <= n; ++i) rd(x[i]);
}
void printInt(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) printInt(x / 10);
  putchar('0' + x % 10);
}
void printLL(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) printLL(x / 10);
  putchar('0' + x % 10);
}
void pr(int x, char ch = '\n') {
  printInt(x);
  putchar(ch);
}
void pr(long long x, char ch = '\n') {
  printLL(x);
  putchar(ch);
}
template <typename T1, typename T2>
void pr(pair<T1, T2> x, char ch = '\n') {
  pr(x.first, ' ');
  pr(x.second, ch);
}
template <typename T>
void pr(T *x, int n) {
  for (int i = 1; i <= n; ++i) pr(x[i], " \n"[i == n]);
}
template <typename T>
void pr(vector<T> &x) {
  int n = x.size();
  for (int i = 1; i <= n; ++i) pr(x[i - 1], " \n"[i == n]);
}
template <typename T>
void cmin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void cmax(T &x, T y) {
  if (y > x) x = y;
}
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int MOD = 1000000007;
int n;
long long a[200005];
long long b[200005];
long long x[200005];
long long dp[200005];
int Q[200005];
double calc(int i2, int i1) {
  return 1.0 * (dp[i2] - dp[i1]) / (x[i2] - x[i1]);
}
struct Solver {
  void InitOnce() {}
  void Read() {
    rd(n);
    rd(a, n);
    rd(b, n);
  }
  void Solve() {
    for (int i = 1; i <= n; ++i) x[i] = -b[i];
    dp[1] = 0;
    int l = 1, r = 0;
    Q[++r] = 1;
    for (int i = 2; i <= n; ++i) {
      while (l < r && calc(Q[l + 1], Q[l]) <= 1.0 * a[i]) ++l;
      dp[i] = dp[Q[l]] + a[i] * b[Q[l]];
      while (l < r && calc(Q[r], Q[r - 1]) >= calc(i, Q[r])) --r;
      Q[++r] = i;
    }
    printf("%lld\n", dp[n]);
  }
} solver;
int main() {
  solver.InitOnce();
  int t = 1;
  t = INF;
  while (t--) {
    solver.Read();
    if (!sc.hasRead) break;
    solver.Solve();
    if (!sc.hasNext) break;
  }
  return 0;
}
