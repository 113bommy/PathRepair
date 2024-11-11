#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
template <class T = int>
inline T readInt();
inline double readDouble();
inline int readUInt();
inline int readChar();
inline void readWord(char *s);
inline bool readLine(char *s);
inline bool isEof();
inline int getChar();
inline int peekChar();
inline bool seekEof();
inline void skipBlanks();
template <class T>
inline void writeInt(T x, char end = 0, int len = -1);
inline void writeChar(int x);
inline void writeWord(const char *s);
inline void writeDouble(double x, int len = 0);
inline void flush();
static struct buffer_flusher_t {
  ~buffer_flusher_t() { flush(); }
} buffer_flusher;
using namespace std;
const int MAXN = 2e3 + 42;
char buff[MAXN];
inline string readString() {
  readWord(buff);
  return string(buff);
}
bool ask(int x, int y) {
  cout << x << " " << y << endl;
  string second;
  cin >> second;
  return second == "black";
}
int main() {
  const int INF = 1e9;
  int n;
  cin >> n;
  int L = 1;
  int R = INF - 1;
  for (int i = 0; i < n - 1; ++i) {
    assert(R - L > 1);
    int M = (L + R) / 2;
    int cM = ask(0, M);
    if (cM) {
      R = M;
    } else {
      L = M;
    }
  }
  int y = R - 1;
  assert(y >= L);
  int cM = ask(42, y);
  if (cM) {
    cout << 42 << ' ' << y - 1 << ' ' << 1 << ' ' << y << endl;
  } else {
    cout << 42 << ' ' << y + 1 << ' ' << 1 << ' ' << y << endl;
  }
}
static const int buf_size = 4096;
static unsigned char buf[buf_size];
static int buf_len = 0, buf_pos = 0;
inline bool isEof() {
  if (buf_pos == buf_len) {
    buf_pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
    if (buf_pos == buf_len) return 1;
  }
  return 0;
}
inline int getChar() { return isEof() ? -1 : buf[buf_pos++]; }
inline int peekChar() { return isEof() ? -1 : buf[buf_pos]; }
inline bool seekEof() {
  int c;
  while ((c = peekChar()) != -1 && c <= 32) buf_pos++;
  return c == -1;
}
inline void skipBlanks() {
  while (!isEof() && buf[buf_pos] <= 32U) buf_pos++;
}
inline int readChar() {
  int c = getChar();
  while (c != -1 && c <= 32) c = getChar();
  return c;
}
inline int readUInt() {
  int c = readChar(), x = 0;
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return x;
}
template <class T>
inline T readInt() {
  int second = 1, c = readChar();
  T x = 0;
  if (c == '-')
    second = -1, c = getChar();
  else if (c == '+')
    c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return second == 1 ? x : -x;
}
inline double readDouble() {
  int second = 1, c = readChar();
  double x = 0;
  if (c == '-') second = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  if (c == '.') {
    c = getChar();
    double coef = 1;
    while ('0' <= c && c <= '9') x += (c - '0') * (coef *= 1e-1), c = getChar();
  }
  return second == 1 ? x : -x;
}
inline void readWord(char *second) {
  int c = readChar();
  while (c > 32) *second++ = c, c = getChar();
  *second = 0;
}
inline bool readLine(char *second) {
  int c = getChar();
  while (c != '\n' && c != -1) *second++ = c, c = getChar();
  *second = 0;
  return c != -1;
}
static int write_buf_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x) {
  if (write_buf_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
  write_buf[write_buf_pos++] = x;
}
inline void flush() {
  if (write_buf_pos)
    fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
}
template <class T>
inline void writeInt(T x, char end, int output_len) {
  if (x < 0) writeChar('-'), x = -x;
  char second[24];
  int n = 0;
  while (x || !n) second[n++] = '0' + x % 10, x /= 10;
  while (n < output_len) second[n++] = '0';
  while (n--) writeChar(second[n]);
  if (end) writeChar(end);
}
inline void writeWord(const char *second) {
  while (*second) writeChar(*second++);
}
inline void writeDouble(double x, int output_len) {
  if (x < 0) writeChar('-'), x = -x;
  int t = (int)x;
  writeInt(t), x -= t;
  writeChar('.');
  for (int i = output_len - 1; i > 0; i--) {
    x *= 10;
    t = std::min(9, (int)x);
    writeChar('0' + t), x -= t;
  }
  x *= 10;
  t = std::min(9, (int)(x + 0.5));
  writeChar('0' + t);
}
