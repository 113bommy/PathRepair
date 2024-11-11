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
int n, m;
vector<int> ans;
struct Solver {
  void InitOnce() {}
  void Read() {
    rd(n);
    rd(m);
  }
  void Solve() {
    ans.clear();
    long long most = 0;
    for (int i = n - 2; i >= 1; i -= 2) most += i;
    if (m > most) {
      puts("-1");
      return;
    }
    ans.push_back(1);
    if (n >= 2) ans.push_back(2);
    int i = 3;
    int cur = 2;
    while (m >= (cur + 1) / 2) {
      ans.push_back(i);
      ++i;
      m -= cur / 2;
      ++cur;
    }
    if (m) {
      while (m < cur / 2) {
        ++i;
        --cur;
      }
      ans.push_back(i);
      m -= cur / 2;
    }
    int BIG = 200000;
    int DELTA = 10001;
    while (n > ans.size()) {
      ans.push_back(BIG);
      BIG += DELTA;
    }
    pr(ans);
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
