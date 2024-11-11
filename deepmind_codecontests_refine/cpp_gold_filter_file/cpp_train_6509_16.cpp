#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const long long LINF = 2e16;
const int magic = 348;
const int MOD = 1e9 + 7;
const double eps = 1e-12;
const double pi = acos(-1);
struct fastio {
  static const int S = 1e7;
  char rbuf[S + 48], wbuf[S + 48];
  int rpos, wpos, len;
  fastio() { rpos = len = wpos = 0; }
  inline char Getchar() {
    if (rpos == len) rpos = 0, len = fread(rbuf, 1, S, stdin);
    if (!len) return EOF;
    return rbuf[rpos++];
  }
  template <class T>
  inline void Get(T &first) {
    char ch;
    bool f;
    T res;
    while (!isdigit(ch = Getchar()) && ch != '-') {
    }
    if (ch == '-')
      f = false, res = 0;
    else
      f = true, res = ch - '0';
    while (isdigit(ch = Getchar())) res = res * 10 + ch - '0';
    first = (f ? res : -res);
  }
  inline void getstring(char *s) {
    char ch;
    while ((ch = Getchar()) <= 32) {
    }
    for (; ch > 32; ch = Getchar()) *s++ = ch;
    *s = '\0';
  }
  inline void flush() {
    fwrite(wbuf, 1, wpos, stdout);
    fflush(stdout);
    wpos = 0;
  }
  inline void Writechar(char ch) {
    if (wpos == S) flush();
    wbuf[wpos++] = ch;
  }
  template <class T>
  inline void Print(T first, char ch) {
    char s[20];
    int pt = 0;
    if (first == 0)
      s[++pt] = '0';
    else {
      if (first < 0) Writechar('-'), first = -first;
      while (first) s[++pt] = '0' + first % 10, first /= 10;
    }
    while (pt) Writechar(s[pt--]);
    Writechar(ch);
  }
  inline void printstring(char *s) {
    int pt = 1;
    while (s[pt] != '\0') Writechar(s[pt++]);
  }
} io;
template <typename T>
inline void check_max(T &first, T cmp) {
  first = max(first, cmp);
}
template <typename T>
inline void check_min(T &first, T cmp) {
  first = min(first, cmp);
}
template <typename T>
inline T myabs(T first) {
  return first >= 0 ? first : -first;
}
template <typename T>
inline T gcd(T first, T second) {
  return second == 0 ? first : gcd(second, first % second);
}
inline int add(int first) {
  if (first >= MOD) first -= MOD;
  return first;
}
inline int add(int first, int MO) {
  if (first >= MO) first -= MO;
  return first;
}
inline int sub(int first) {
  if (first < 0) first += MOD;
  return first;
}
inline int sub(int first, int MO) {
  if (first < 0) first += MO;
  return first;
}
inline void Add(int &first, int second) { first = add(first + second); }
inline void Add(int &first, int second, int MO) {
  first = add(first + second, MO);
}
inline void Sub(int &first, int second) { first = sub(first - second); }
inline void Sub(int &first, int second, int MO) {
  first = sub(first - second, MO);
}
template <typename T>
inline int quick_pow(int first, T second) {
  int res = 1;
  while (second) {
    if (second & 1) res = 1ll * res * first % MOD;
    first = 1ll * first * first % MOD;
    second >>= 1;
  }
  return res;
}
template <typename T>
inline int quick_pow(int first, T second, int MO) {
  int res = 1;
  while (second) {
    if (second & 1) res = 1ll * res * first % MO;
    first = 1ll * first * first % MO;
    second >>= 1;
  }
  return res;
}
const int MAXN = 2e5;
inline bool islarger(double first, double second) {
  return first - second > eps;
}
inline bool issmaller(double first, double second) {
  return first - second < -eps;
}
inline bool isequal(double first, double second) {
  return (!islarger(first, second)) && (!issmaller(first, second));
}
int n, k;
int t[MAXN + 48];
double dp[51][MAXN + 48];
double p[MAXN + 48], q[MAXN + 48], r[MAXN + 48];
inline void init() {
  for (register int i = 1; i <= n; i++) p[i] = p[i - 1] + t[i];
  for (register int i = 1; i <= n; i++) q[i] = q[i - 1] + double(1.0) / t[i];
  for (register int i = 1; i <= n; i++)
    r[i] = r[i - 1] + double(1.0) * double(t[i]) * q[i - 1];
}
inline double calc_k(double x1, double y1, double x2, double y2) {
  if (isequal(x1, x2)) return 1e16;
  return (y1 - y2) / (x1 - x2);
}
inline double calc(int left, int right) {
  return p[right] * q[right] - p[left - 1] * q[right] - r[right] + r[left - 1];
}
struct node {
  double first, second;
  int ind;
  node() {}
  inline node(double _x, double _y, int _i) {
    first = _x;
    second = _y;
    ind = _i;
  }
} Q[MAXN + 48];
int head, tail;
int main() {
  scanf("%d%d", &n, &k);
  for (register int i = 1; i <= n; i++) scanf("%d", t + i);
  init();
  for (register int i = 1; i <= n; i++) dp[1][i] = calc(1, i);
  for (register int layer = 2; layer <= k; layer++) {
    head = tail = 1;
    Q[1] =
        node(p[layer - 1], dp[layer - 1][layer - 1] + r[layer - 1], layer - 1);
    for (register int i = layer; i <= n; i++) {
      while (head < tail &&
             issmaller(calc_k(Q[head].first, Q[head].second, Q[head + 1].first,
                              Q[head + 1].second),
                       q[i]))
        head++;
      int chosen = Q[head].ind;
      dp[layer][i] = dp[layer - 1][chosen] + calc(chosen + 1, i);
      Q[++tail] = node(p[i], dp[layer - 1][i] + r[i], i);
      while (head + 1 < tail &&
             issmaller(calc_k(Q[tail - 1].first, Q[tail - 1].second,
                              Q[tail].first, Q[tail].second),
                       calc_k(Q[tail - 2].first, Q[tail - 2].second,
                              Q[tail - 1].first, Q[tail - 1].second)))
        Q[tail - 1] = Q[tail], tail--;
    }
  }
  printf("%.10lf\n", dp[k][n]);
  io.flush();
  return 0;
}
