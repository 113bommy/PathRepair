#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
namespace fastinput {
template <class T = int>
inline T readInt();
inline long double readDouble();
inline int readUInt();
inline int readChar();
inline void readWord(char *s);
inline bool readLine(char *s);
inline bool isEof();
inline int peekChar();
inline bool seekEof();
template <class T>
inline void writeInt(T x, int len = -1);
template <class T>
inline void writeUInt(T x, int len = -1);
inline void writeChar(int x);
inline void writeWord(const char *s);
inline void writeDouble(long double x, int len = 0);
inline void flush();
static const int buf_size = 4096;
static char buf[buf_size];
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
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}
inline long double readDouble() {
  int s = 1, c = readChar();
  long double x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  if (c == '.') {
    c = getChar();
    long double coef = 1;
    while ('0' <= c && c <= '9') x += (c - '0') * (coef *= 0.1), c = getChar();
  }
  return s == 1 ? x : -x;
}
inline void readWord(char *s) {
  int c = readChar();
  while (c > 32) *s++ = (char)c, c = getChar();
  *s = 0;
}
inline bool readLine(char *s) {
  int c = getChar();
  while (c != '\n' && c != -1) *s++ = (char)c, c = getChar();
  *s = 0;
  return c != -1;
}
static int write_buf_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x) {
  if (write_buf_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_buf_pos = 0;
  write_buf[write_buf_pos++] = (char)x;
}
inline void flush() {
  if (write_buf_pos)
    fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
}
template <class T>
inline void writeInt(T x, int output_len) {
  if (x < 0) writeChar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n) s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len) s[n++] = '0';
  while (n--) writeChar(s[n]);
}
template <class T>
inline void writeUInt(T x, int output_len) {
  char s[24];
  int n = 0;
  while (x || !n) s[n++] = (char)('0' + (char)(x % 10)), x /= 10;
  while (n < output_len) s[n++] = '0';
  while (n--) writeChar(s[n]);
}
inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}
inline void writeDouble(long double x, int output_len) {
  if (x < 0) writeChar('-'), x = -x;
  int t = (int)x;
  writeUInt(t), x -= t;
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
}  // namespace fastinput
using namespace fastinput;
using namespace std;
const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
inline void *operator new(size_t n) {
  mpos += n;
  return (void *)(mem + mpos - n);
}
inline void operator delete(void *) noexcept {}
const int N = 500;
pair<long long, long long> dp[N];
int a[N];
int main() {
  int n = readInt();
  for (int i = 1; i <= n; ++i) {
    a[i] = readInt();
  }
  dp[n + 1] = {0, 0};
  for (int i = n; i >= 1; --i) {
    long long sum = 0;
    for (int j = i; j <= n; ++j) {
      pair<long long, long long> temp = dp[j + 1];
      swap(temp.first, temp.second);
      temp.first += a[j];
      temp.second += sum;
      dp[i] = max(dp[i], temp);
      sum += a[i];
    }
  }
  cout << dp[1].second << " " << dp[1].first << "\n";
  return 0;
}
