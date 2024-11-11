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
const int MOD = 998244353;
int n;
int a[400005];
int m;
pair<int, int> p[400005];
int cnt[400005];
int suf[400005];
vector<int> b[400005];
int go() {
  while (m >= 1 && p[m].first == 0) --m;
  assert(m >= 1);
  --p[m].first;
  return p[m].second;
}
struct Solver {
  void InitOnce() {}
  void Read() {
    rd(n);
    rd(a, n);
  }
  void Solve() {
    sort(a + 1, a + 1 + n);
    m = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] == p[m].second)
        ++p[m].first;
      else {
        p[++m].second = a[i];
        p[m].first = 1;
      }
    }
    sort(p + 1, p + 1 + m);
    for (int i = 1; i <= n + 1; ++i) cnt[i] = 0, suf[i] = 0;
    for (int i = 1; i <= m; ++i) ++cnt[p[i].first];
    for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + cnt[i];
    int w = 0, h = 0, cursum = 0;
    for (int i = 1; i * i <= n; ++i) {
      cursum += cnt[i] * i;
      int tmp = cursum + suf[i + 1] * i;
      int tw = i;
      int th = tmp / tw;
      if (tw > th) continue;
      tmp = tw * th;
      if (tmp > w * h) {
        w = tw;
        h = th;
      }
    }
    pr(w * h);
    printf("%d %d\n", h, w);
    for (int i = 0; i < h; ++i) {
      b[i].clear();
      b[i].resize(w);
    }
    for (int i = m; i >= 1; --i) {
      if (p[i].first > w) p[i].first = w;
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) b[(i + j) % h][j] = go();
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) printf("%d ", b[i][j]);
      printf("\n");
    }
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
