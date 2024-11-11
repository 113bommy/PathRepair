#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long linf = (long long)1e18;
const double eps = 1e-6;
template <class T>
string tostr(T a) {
  ostringstream out;
  out << a;
  return out.str();
}
struct debugger {
  template <typename T>
  debugger &operator,(const T &x) {
    cerr << x << endl;
    return *this;
  }
} dbg;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
}
inline void read(long long &x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
}
inline void read(bool &x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
}
inline void read(double &x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (ch == '.') {
    double tmp = 1;
    ch = nc();
    for (; ch >= '0' && ch <= '9'; ch = nc())
      tmp /= 10.0, x += tmp * (ch - '0');
  }
  if (sign) x = -x;
}
inline void read(char *s) {
  char ch = nc();
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return;
  for (; !blank(ch) && !IOerror; ch = nc()) *s++ = ch;
  *s = 0;
}
inline void read(char &c) {
  for (c = nc(); blank(c); c = nc())
    ;
  if (IOerror) {
    c = -1;
    return;
  }
}
inline void read1(int &x) {
  char ch;
  int bo = 0;
  x = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') bo = 1;
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar())
    ;
  if (bo) x = -x;
}
inline void read1(long long &x) {
  char ch;
  int bo = 0;
  x = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') bo = 1;
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar())
    ;
  if (bo) x = -x;
}
inline void read1(double &x) {
  char ch;
  int bo = 0;
  x = 0;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') bo = 1;
  for (; ch >= '0' && ch <= '9'; x = x * 10 + ch - '0', ch = getchar())
    ;
  if (ch == '.') {
    double tmp = 1;
    for (ch = getchar(); ch >= '0' && ch <= '9';
         tmp /= 10.0, x += tmp * (ch - '0'), ch = getchar())
      ;
  }
  if (bo) x = -x;
}
inline void read1(char *s) {
  char ch = getchar();
  for (; blank(ch); ch = getchar())
    ;
  for (; !blank(ch); ch = getchar()) *s++ = ch;
  *s = 0;
}
inline void read1(char &c) {
  for (c = getchar(); blank(c); c = getchar())
    ;
}
inline void read2(int &x) { scanf("%d", &x); }
inline void read2(long long &x) { scanf("%lld", &x); }
inline void read2(double &x) { scanf("%lf", &x); }
inline void read2(char *s) { scanf("%s", s); }
inline void read2(char &c) { scanf(" %c", &c); }
inline void readln2(char *s) { gets(s); }
struct Ostream_fwrite {
  char *buf, *p1, *pend;
  Ostream_fwrite() {
    buf = new char[100000];
    p1 = buf;
    pend = buf + 100000;
  }
  void out(char ch) {
    if (p1 == pend) {
      fwrite(buf, 1, 100000, stdout);
      p1 = buf;
    }
    *p1++ = ch;
  }
  void print(int x) {
    static char s[15], *s1;
    s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) out('-'), x = -x;
    while (x) *s1++ = x % 10 + '0', x /= 10;
    while (s1-- != s) out(*s1);
  }
  void println(int x) {
    static char s[15], *s1;
    s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) out('-'), x = -x;
    while (x) *s1++ = x % 10 + '0', x /= 10;
    while (s1-- != s) out(*s1);
    out('\n');
  }
  void print(long long x) {
    static char s[25], *s1;
    s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) out('-'), x = -x;
    while (x) *s1++ = x % 10 + '0', x /= 10;
    while (s1-- != s) out(*s1);
  }
  void println(long long x) {
    static char s[25], *s1;
    s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) out('-'), x = -x;
    while (x) *s1++ = x % 10 + '0', x /= 10;
    while (s1-- != s) out(*s1);
    out('\n');
  }
  void print(double x, int y) {
    static long long mul[] = {1,
                              10,
                              100,
                              1000,
                              10000,
                              100000,
                              1000000,
                              10000000,
                              100000000,
                              1000000000,
                              10000000000LL,
                              100000000000LL,
                              1000000000000LL,
                              10000000000000LL,
                              100000000000000LL,
                              1000000000000000LL,
                              10000000000000000LL,
                              100000000000000000LL};
    if (x < -1e-7) out('-'), x = -x;
    x *= mul[y];
    long long x1 = (long long)floor(x);
    if (x - floor(x) >= 0.5) ++x1;
    long long x2 = x1 / mul[y];
    print(x2);
    if (y > 0) {
      out('.');
      print(x1 - x2 * mul[y]);
    }
  }
  void println(double x, int y) {
    print(x, y);
    out('\n');
  }
  void print(char *s) {
    while (*s) out(*s++);
  }
  void println(char *s) {
    while (*s) out(*s++);
    out('\n');
  }
  void flush() {
    if (p1 != buf) {
      fwrite(buf, 1, p1 - buf, stdout);
      p1 = buf;
    }
  }
  ~Ostream_fwrite() { flush(); }
} Ostream;
inline void print(int x) { Ostream.print(x); }
inline void println(int x) { Ostream.println(x); }
inline void print(char x) { Ostream.out(x); }
inline void println(char x) {
  Ostream.out(x);
  Ostream.out('\n');
}
inline void print(long long x) { Ostream.print(x); }
inline void println(long long x) { Ostream.println(x); }
inline void print(double x, int y) { Ostream.print(x, y); }
inline void println(double x, int y) { Ostream.println(x, y); }
inline void print(char *s) { Ostream.print(s); }
inline void println(char *s) { Ostream.println(s); }
inline void println() { Ostream.out('\n'); }
inline void flush() { Ostream.flush(); }
char Out[100000], *o = Out;
inline void print1(int x) {
  static char buf[15];
  char *p1 = buf;
  if (!x) *p1++ = '0';
  if (x < 0) *o++ = '-', x = -x;
  while (x) *p1++ = x % 10 + '0', x /= 10;
  while (p1-- != buf) *o++ = *p1;
}
inline void println1(int x) {
  print1(x);
  *o++ = '\n';
}
inline void print1(long long x) {
  static char buf[25];
  char *p1 = buf;
  if (!x) *p1++ = '0';
  if (x < 0) *o++ = '-', x = -x;
  while (x) *p1++ = x % 10 + '0', x /= 10;
  while (p1-- != buf) *o++ = *p1;
}
inline void println1(long long x) {
  print1(x);
  *o++ = '\n';
}
inline void print1(char c) { *o++ = c; }
inline void println1(char c) {
  *o++ = c;
  *o++ = '\n';
}
inline void print1(char *s) {
  while (*s) *o++ = *s++;
}
inline void println1(char *s) {
  print(s);
  *o++ = '\n';
}
inline void println1() { *o++ = '\n'; }
inline void flush1() {
  if (o != Out && *(o - 1) == '\n') *--o = 0;
  puts(Out);
}
struct puts_write {
  ~puts_write() { flush1(); }
};
inline void print2(int x) { printf("%d", x); }
inline void println2(int x) { printf("%d\n", x); }
inline void print2(char x) { printf("%c", x); }
inline void println2(char x) { printf("%c\n", x); }
inline void print2(long long x) { printf("%lld", x); }
inline void println2(long long x) {
  print2(x);
  printf("\n");
}
inline void println2() { printf("\n"); }
};  // namespace fastIO
using namespace fastIO;
string name = "", in = ".in", out = ".out";
bool a[2005][2005], visit[2005][2005];
int cx[700005], cy[700005], c1, n, cnt, cntC, cntS;
double dist[700005], Ox, Oy;
void dfs(int x, int y) {
  if (visit[x][y]) return;
  visit[x][y] = 1;
  ++cnt;
  bool bo = 0;
  Ox += x;
  Oy += y;
  for (int dx = -1; dx <= 1; ++dx)
    for (int dy = -1; dy <= 1; ++dy) {
      int x1 = x + dx, y1 = y + dy;
      if (!a[x1][y1])
        ++bo;
      else
        dfs(x1, y1);
    }
  if (bo) ++c1, cx[c1] = x, cy[c1] = y;
}
void genMap() {
  static bool tmp[2005][2005];
  memcpy(tmp, a, sizeof(a));
  memset(a, 0, sizeof(a));
  for (int i = 4; i + 3 <= n; ++i)
    for (int j = 4; j + 3 <= n; ++j) {
      int cnt = 0;
      for (int dx = -3; dx <= 3; ++dx)
        for (int dy = -3; dy <= 3; ++dy) cnt += tmp[i + dx][j + dy];
      if (cnt >= 24)
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
}
int main() {
  read(n);
  memset(visit, 1, sizeof(visit));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) read(a[i][j]), visit[i][j] = 0;
  genMap();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!visit[i][j] && a[i][j]) {
        c1 = 0;
        cnt = 0;
        Ox = 0;
        Oy = 0;
        dfs(i, j);
        if (cnt < 130) continue;
        double max_d = 0;
        int c1_pre = c1;
        Ox /= cnt;
        Oy /= cnt;
        for (int k = 1; k <= c1; ++k)
          dist[k] =
              sqrt((Ox - cx[k]) * (Ox - cx[k]) + (Oy - cy[k]) * (Oy - cy[k]));
        for (int k = 1; k <= c1; ++k) max_d = max(max_d, dist[k]);
        for (int k = 1; k <= c1; ++k) dist[k] /= max_d;
        double ave = accumulate(dist + 1, dist + c1 + 1, 0.0) / c1, sum = 0;
        for (int k = 1; k <= c1; ++k) sum += (dist[k] - ave) * (dist[k] - ave);
        sum /= c1;
        sum = sqrt(sum);
        double div = sum / ave;
        if (div > 0.045 && div < 0.055) {
          printf("div=%.5lf cnt=%d\n", div, cnt);
          while (1)
            ;
        }
        if (div < 0.060)
          ++cntC;
        else
          ++cntS;
      }
end:;
  printf("%d %d\n", cntC, cntS);
  return 0;
}
