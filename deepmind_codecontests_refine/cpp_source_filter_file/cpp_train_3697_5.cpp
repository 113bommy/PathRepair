#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
inline int readChar();
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);
static const int buf_size = 4096;
inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}
inline int readChar() {
  int c = getChar();
  while (c <= 32) c = getChar();
  return c;
}
template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}
static int write_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}
template <class T>
inline void writeInt(T x, char end) {
  if (x < 0) writeChar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n) s[n++] = '0' + x % 10, x /= 10;
  while (n--) writeChar(s[n]);
  if (end) writeChar(end);
}
inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}
struct Flusher {
  ~Flusher() {
    if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;
const int MAXN = 2001;
const double eps = 1e-9;
double divide(double a, double b) { return a / b; }
int signum(double x) { return x < -eps ? -1 : x > eps; }
struct point {
  point() {}
  double getcoord() const {
    if (signum(x) == 0) {
      return 1e30;
    }
    return y / x;
  }
  bool z() const { return signum(x) == 0 && signum(y) == 0; }
  double x, y;
};
point getpoint(double x, double y) {
  point a;
  a.x = x;
  a.y = y;
  return a;
}
point operator-(const point &a, const point &b) {
  return getpoint(a.x - b.x, a.y - b.y);
}
int n, a[MAXN], b[MAXN], c[MAXN];
point p[MAXN];
int main() {
  n = readInt();
  for (int i = 0; i < n; i++) {
    a[i] = readInt(), b[i] = readInt(), c[i] = readInt();
    int s = a[i] * a[i] + b[i] * b[i];
    p[i] = getpoint(divide(a[i] * c[i], s), divide(b[i] * c[i], s));
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<double> lines;
    bool z = false;
    for (int j = i + 1; j < n; j++) {
      point q = p[j] - p[i];
      if (q.z()) {
        z = true;
      } else {
        lines.push_back(q.getcoord());
      }
    }
    sort(lines.begin(), lines.end());
    for (int j = 0; j < (int)(lines).size();) {
      int k = j;
      while (k < (int)(lines).size() && signum(lines[j] - lines[k]) == 0) {
        k++;
      }
      ans += (k - j) * (k - j - 1) / 2;
      if (z) {
        ans += k - j;
      }
      j = k;
    }
  }
  printf("%d\n", ans);
  return 0;
}
