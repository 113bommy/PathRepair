#include <bits/stdc++.h>
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
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  else if (c == '+')
    c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}
inline double readDouble() {
  int s = 1, c = readChar();
  double x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  if (c == '.') {
    c = getChar();
    double coef = 1;
    while ('0' <= c && c <= '9') x += (c - '0') * (coef *= 1e-1), c = getChar();
  }
  return s == 1 ? x : -x;
}
inline void readWord(char *s) {
  int c = readChar();
  while (c > 32) *s++ = c, c = getChar();
  *s = 0;
}
inline bool readLine(char *s) {
  int c = getChar();
  while (c != '\n' && c != -1) *s++ = c, c = getChar();
  *s = 0;
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
  if (write_buf_pos) {
    fwrite(write_buf, 1, write_buf_pos, stdout), write_buf_pos = 0;
    fflush(stdout);
  }
}
template <class T>
inline void writeInt(T x, char end, int output_len) {
  if (x < 0) writeChar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n) s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len) s[n++] = '0';
  while (n--) writeChar(s[n]);
  if (end) writeChar(end);
}
inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
using namespace std;
mt19937 Random(time(0));
const long long INF = 1e9 + 10;
const long long MOD = 1e9 + 7;
const long long P = 239017;
const long long BINF = 1e18 + 10;
const long long N = 1e5 + 10;
const long long LOG = 20;
vector<long long> g[N];
long long calc[N], sum[N], h[N], up[N][LOG], mx_up[N], cost[N], max_len, w;
pair<long long, long long> dp[N];
void precalc(long long v, long long cur_sum = 0, long long p = 0) {
  up[v][0] = p;
  sum[v] = cur_sum;
  h[v] = h[p] + 1;
  for (auto u : g[v]) {
    precalc(u, cur_sum + cost[v], v);
  }
}
void dfs(long long v) {
  pair<long long, long long> best = {-BINF, -BINF};
  for (auto u : g[v]) {
    dfs(u);
    calc[v] += calc[u];
    long long cnt = min(max_len - dp[u].second, mx_up[u]);
    best = max(best, {cnt, u});
  }
  if (best.first <= 0) {
    calc[v]++;
    dp[v] = {cost[v], 1};
  } else {
    dp[v] = {dp[best.second].first + cost[v], dp[best.second].second};
  }
  long long cur = v;
  for (long long i = LOG - 1; i >= 0; i--) {
    if (!up[cur][i]) {
      continue;
    }
    if (dp[v].first + sum[v] - sum[up[cur][i]] <= w) {
      cur = up[cur][i];
      mx_up[v] |= 1 << i;
    }
  }
}
void source() {
  long long n = readInt();
  max_len = readInt(), w = readInt<long long>();
  for (long long i = 1; i <= n; i++) {
    cost[i] = readInt();
    if (cost[i] > w) {
      writeInt(-1);
      exit(0);
    }
  }
  for (long long i = 2; i <= n; i++) {
    long long p = readInt();
    g[p].push_back(i);
  }
  precalc(1);
  for (long long i = 1; i < LOG; i++) {
    for (long long j = 1; j <= n; j++) {
      up[j][i] = up[up[j][i - 1]][i - 1];
    }
  }
  dfs(1);
  writeInt(calc[1]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}
