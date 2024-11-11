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
int x[200005];
int v[200005];
pair<int, int> p[200005];
struct Treap {
  static const int MAXN = 200000 + 10;
  int top, root, ch[MAXN][2], rnd[MAXN];
  pair<int, long long> val[MAXN];
  long long sum[MAXN];
  int NewNode(pair<int, long long> v) {
    int id = ++top;
    ch[id][0] = 0, ch[id][1] = 0, rnd[id] = rand();
    val[id] = v;
    sum[id] = 1LL * v.second;
    return id;
  }
  void PushUp(int id) {
    sum[id] = sum[ch[id][0]] + sum[ch[id][1]] + 1LL * val[id].second;
  }
  void Rotate(int &id, int d) {
    int tmp = ch[id][d ^ 1];
    ch[id][d ^ 1] = ch[tmp][d];
    ch[tmp][d] = id, id = tmp;
    PushUp(ch[id][d]), PushUp(id);
  }
  void InsertHelp(int &id, pair<int, long long> v) {
    if (!id) {
      id = NewNode(v);
      return;
    }
    if (v.first == val[id].second)
      val[id].second += v.second;
    else {
      int d = val[id].first > v.first ? 0 : 1;
      InsertHelp(ch[id][d], v);
      if (rnd[id] < rnd[ch[id][d]]) Rotate(id, d ^ 1);
    }
    PushUp(id);
  }
  void Init() { top = 0, root = 0; }
  void Insert(pair<int, int> v) { InsertHelp(root, v); }
  long long GetSumValue(int v) {
    int id = root;
    long long res = 0;
    while (id) {
      if (val[id].first > v)
        id = ch[id][0];
      else if (val[id].first == v) {
        res += sum[ch[id][0]] + 1LL * val[id].second;
        break;
      } else {
        res += sum[ch[id][0]] + 1LL * val[id].second;
        id = ch[id][1];
      }
    }
    return res;
  }
} treap1, treap2;
struct Solver {
  void InitOnce() {}
  void Read() {
    rd(n);
    rd(x, n);
    rd(v, n);
    for (int i = 1; i <= n; ++i) {
      p[i].first = x[i];
      p[i].second = v[i];
    }
  }
  void Solve() {
    treap1.Init();
    treap2.Init();
    sort(p + 1, p + 1 + n);
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += treap2.GetSumValue(p[i].second) * p[i].first;
      sum -= treap1.GetSumValue(p[i].second);
      treap1.Insert({p[i].second, p[i].first});
      treap2.Insert({p[i].second, 1});
    }
    pr(sum);
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
