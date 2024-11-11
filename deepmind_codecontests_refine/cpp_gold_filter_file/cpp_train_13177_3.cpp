#include <bits/stdc++.h>
using namespace std;
namespace fastinput {
inline int readChar();
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);
static const int buf_size = 16384;
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
  while (x || !n) s[n++] = (char)('0' + x % 10), x /= 10;
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
}  // namespace fastinput
using namespace fastinput;
const long long INF = 1e16;
map<long long, int> sums;
vector<long long> vals;
int main() {
  int n = readInt(), k = readInt();
  vals.push_back(1);
  if (abs(k) != 1) {
    while (abs(vals.back()) < INF) vals.push_back(vals.back() * k);
  }
  if (k == -1) vals.push_back(k);
  sums[0] = 1;
  long long pref = 0;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int x = readInt();
    pref += x;
    for (auto y : vals)
      if (sums.count(pref - y)) res += sums[pref - y];
    ++sums[pref];
  }
  cout << res << endl;
  return 0;
}
