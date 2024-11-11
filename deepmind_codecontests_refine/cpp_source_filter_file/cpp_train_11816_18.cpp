#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
#pragma warning(disable : 4996)
#pragma hdrstop
using namespace std;
inline bool isDigit(const char ch) { return (ch >= '0' && ch <= '9'); }
class IO {
 public:
  static const int IO_ERR = -1;
  static const int BUFFER_SIZE = 1 << 18;
  bool eof;
  char curChar;
  IO() : rbCount(0), rbOffset(0), curChar(0), eof(false) {}
  ~IO() { fwrite(writeBuffer, sizeof(writeBuffer[0]), wbOffset, stdout); }
  inline int nextInt();
  IO& operator>>(int& x);
  void newline();
  void printLong(long long x);
  IO& operator<<(long long x);
  IO& operator<<(ostream& (*fn)(ostream&));

 private:
  char readBuffer[BUFFER_SIZE], writeBuffer[BUFFER_SIZE];
  size_t rbCount, rbOffset, wbOffset;
};
extern bool useFastIO;
extern istream* pin;
extern ostream* pout;
extern IO io;
inline int nextInt() {
  if (useFastIO) {
    return io.nextInt();
  }
  int ret;
  *pin >> ret;
  return ret;
}
inline void newline() {
  if (useFastIO) {
    io.newline();
    return;
  }
  *pout << endl;
}
inline void printLong(long long x) {
  if (useFastIO) {
    io.printLong(x);
    return;
  }
  *pout << x;
}
inline long long ppow(long long a, long long b, long long md) {
  long long ret = 1;
  a %= md;
  while (b) {
    if (b & 1) {
      ret = ret * a % md;
    }
    a = a * a % md;
    b >>= 1;
  }
  return ret % md;
}
template <class T>
T inverseElement(const T n, const T mod) {
  return ppow(n, mod - 2, mod);
}
namespace Random {}
IO io;
const int MOD = 1000000007;
const int MAXN = 111111;
int h, w, n, x, y;
pair<int, int> a[MAXN];
long long fact[MAXN], invfact[MAXN], res[MAXN];
inline int binom(int n, int k) {
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}
inline int getval(int x, int y) { return binom(y + x - 2, x - 1); }
inline bool inside(int x, int y) {
  return ((a[x].first <= a[y].first && a[x].second <= a[y].second));
}
void solve(istream& ins, ostream& out) {
  fact[0] = 1;
  invfact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    invfact[i] = inverseElement(fact[i], (long long)MOD);
  }
  io >> h >> w >> n;
  for (int i = 0; i < n; ++i) {
    io >> x >> y;
    a[i] = make_pair(x, y);
  }
  a[n++] = make_pair(h, w);
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    res[i] = getval(a[i].first, a[i].second);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (!inside(i, j)) {
        continue;
      }
      if ((res[j] -=
           res[i] *
           getval(a[j].first - a[i].first + 1, a[j].second - a[i].second + 1) %
           MOD) < 0) {
        res[j] += MOD;
      }
    }
  }
  io << res[n - 1] << endl;
}
extern class IO io;
bool useFastIO = false;
istream* pin;
ostream* pout;
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  useFastIO = true;
  ostream& out = cout;
  out << fixed << setprecision(16);
  pin = &in;
  pout = &out;
  solve(in, out);
  return 0;
}
inline int IO::nextInt() {
  while (!eof && !isDigit(curChar) && curChar != '-') {
    if (rbOffset == rbCount) {
      rbCount =
          fread(readBuffer, sizeof(readBuffer[0]), sizeof(readBuffer), stdin);
      if (rbCount <= 0) {
        eof = true;
        return IO_ERR;
      }
      rbOffset = 0;
    }
    curChar = readBuffer[rbOffset++];
  }
  bool neg = false;
  if (curChar == '-') {
    neg = true;
    if (rbOffset == rbCount) {
      rbCount =
          fread(readBuffer, sizeof(readBuffer[0]), sizeof(readBuffer), stdin);
      if (rbCount <= 0) {
        eof = true;
        return IO_ERR;
      }
      rbOffset = 0;
    }
    curChar = readBuffer[rbOffset++];
  }
  int result = 0;
  while (!eof && isDigit(curChar)) {
    result = (result << 3) + (result << 1) + curChar - '0';
    if (rbOffset == rbCount) {
      rbCount =
          fread(readBuffer, sizeof(readBuffer[0]), sizeof(readBuffer), stdin);
      if (rbCount <= 0) {
        eof = true;
        return (neg ? -result : result);
      }
      rbOffset = 0;
    }
    curChar = readBuffer[rbOffset++];
  }
  return (neg ? -result : result);
}
IO& IO::operator>>(int& x) {
  x = ::nextInt();
  return *this;
}
void IO::newline() {
  if (wbOffset == BUFFER_SIZE) {
    fwrite(writeBuffer, sizeof(writeBuffer[0]), wbOffset, stdout);
    wbOffset = 0;
  }
  writeBuffer[wbOffset++] = '\n';
}
void IO::printLong(long long x) {
  if (wbOffset + 22 > BUFFER_SIZE) {
    fwrite(writeBuffer, sizeof(writeBuffer[0]), wbOffset, stdout);
    wbOffset = 0;
  }
  if (x < 0) {
    writeBuffer[wbOffset++] = '-';
    x = -x;
  } else if (!x) {
    writeBuffer[wbOffset++] = '0';
    return;
  }
  int st = wbOffset;
  while (x) {
    writeBuffer[wbOffset++] = x % 10 + '0';
    x /= 10;
  }
  for (int l = st, r = wbOffset - 1; l < r; ++l, --r) {
    char t = writeBuffer[l];
    writeBuffer[l] = writeBuffer[r];
    writeBuffer[r] = t;
  }
}
IO& IO::operator<<(long long x) {
  ::printLong(x);
  return *this;
}
IO& IO::operator<<(ostream& (*fn)(ostream&)) {
  ::newline();
  return *this;
}
