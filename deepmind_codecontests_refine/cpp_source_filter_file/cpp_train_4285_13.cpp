#include <bits/stdc++.h>
namespace IO {
int double_len(6);
bool spacebar_can_see(1);
template <typename T>
class Number {
 public:
  unsigned int len;
  int hex;
  T number;
  inline Number(T number = 0, int hex = 10, int len = 0)
      : number(number), hex(hex), len(len) {}
  inline operator T() { return number; }
};
inline bool CanSee(char ch) {
  return spacebar_can_see ? (31 < ch && ch < 127) : (32 < ch && ch < 127);
}
inline bool IsNumber(char ch) { return (47 < ch && ch < 58); }
static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;
inline char GetChar() {
  static char buf[IN_BUF], *ps = buf, *pt = buf;
  if (ps == pt) {
    ps = buf;
    pt = buf + fread(buf, 1, IN_BUF, stdin);
  }
  return ps == pt ? EOF : *ps++;
}
inline void PutChar(char ch) {
  static char pbuf[OUT_BUF], *pp = pbuf;
  struct Flusher {
    ~Flusher() { fwrite(pbuf, 1, pp - pbuf, stdout); }
  };
  static Flusher out_put_flusher;
  if (pp == pbuf + OUT_BUF) {
    fwrite(pbuf, 1, OUT_BUF, stdout);
    pp = pbuf;
  }
  *pp++ = ch;
}
char read_ch = '\n';
template <class T>
inline T ReadInt() {
  register T x(0);
  register bool f(1);
  while (!IsNumber(read_ch)) {
    if (read_ch == 45) {
      f = 0;
    }
    read_ch = GetChar();
  }
  while (IsNumber(read_ch)) {
    x = (x << 1) + (x << 3) + (read_ch ^ 48);
    read_ch = GetChar();
  }
  return f ? x : -x;
}
template <class T>
inline T ReadUInt() {
  register T x(0);
  while (!IsNumber(read_ch)) {
    read_ch = GetChar();
  }
  while (IsNumber(read_ch)) {
    x = (x << 1) + (x << 3) + (read_ch ^ 48);
    read_ch = GetChar();
  }
  return x;
}
inline double ReadDouble() {
  register long long int_num(ReadInt<long long>());
  if (read_ch == 46) {
    register double pow10(1.0), result(0);
    read_ch = GetChar();
    while (IsNumber(read_ch)) {
      pow10 /= 10.0;
      result += pow10 * (read_ch ^ 48);
      read_ch = GetChar();
    }
    return int_num + (int_num < 0 ? -result : result);
  } else {
    return (double)int_num;
  }
}
inline void ReadT(int &x) { x = ReadInt<int>(); }
inline void ReadT(long long &x) { x = ReadInt<long long>(); }
inline void ReadT(bool &x) { x = ReadUInt<bool>(); }
inline void ReadT(unsigned int &x) { x = ReadUInt<unsigned int>(); }
inline void ReadT(unsigned long long &x) { x = ReadUInt<unsigned long long>(); }
inline void ReadT(double &x) { x = ReadDouble(); }
inline void ReadT(char &s) {
  for (; !CanSee(read_ch) && (~read_ch); read_ch = GetChar())
    ;
  s = read_ch;
  read_ch = 10;
}
inline void ReadT(char *s) {
  register int len(0);
  for (; !CanSee(read_ch) && (~read_ch); read_ch = GetChar())
    ;
  for (; CanSee(read_ch) && (~read_ch); read_ch = GetChar()) {
    s[len++] = read_ch;
  }
  s[len] = 0;
  read_ch = 10;
}
template <typename T>
inline void ReadT(Number<T> &x) {
  ReadT(x.number);
}
template <typename T>
inline void Read(T &t) {
  ReadT(t);
}
template <typename T, typename... Args>
void Read(T &t, Args &...args) {
  ReadT(t);
  Read(args...);
}
const char NUMBER[36] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66,
                         67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78,
                         79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
template <typename T>
void WriteInt(T x) {
  if (x < 0) {
    PutChar(45);
    x = -x;
  }
  if (9 < x) {
    WriteInt(x / 10);
  }
  PutChar(x % 10 ^ 48);
}
template <typename T>
void WriteUInt(T x) {
  if (9 < x) {
    WriteInt(x / 10);
  }
  PutChar(x % 10 ^ 48);
}
template <typename T>
void WriteKInt(T x, int hex, int len) {
  if (x < 0) {
    PutChar(45);
    --len;
    x = -x;
  }
  if (hex <= x || 1 < len) {
    WriteKInt(x / hex, hex, len - 1);
  }
  PutChar(NUMBER[x % hex]);
}
template <typename T>
void WriteUKInt(T x, int hex, int len) {
  if (hex <= x || 1 < len) {
    WriteKInt(x / hex, hex, len - 1);
  }
  PutChar(NUMBER[x % hex]);
}
inline void WriteDouble(double x, int len) {
  if (x < 0) {
    x = -x;
    PutChar(45);
  }
  WriteUInt((unsigned long long)x);
  if (len) {
    x -= (int)x;
    PutChar(46);
    while (len--) {
      x *= 10;
      if (!(unsigned long long)x) {
        PutChar(48);
      }
    }
    WriteUInt((unsigned long long)x);
  }
}
inline void WriteT(int x) { WriteInt<int>(x); }
inline void WriteT(long long x) { WriteInt<long long>(x); }
inline void WriteT(bool x) { WriteUInt<bool>(x); }
inline void WriteT(unsigned int x) { WriteUInt<unsigned int>(x); }
inline void WriteT(unsigned long long x) { WriteUInt<unsigned long long>(x); }
inline void WriteT(double x) { WriteDouble(x, double_len); }
inline void WriteT(char *s) {
  int len(strlen(s));
  while (len--) {
    PutChar(*s++);
  }
}
inline void WriteT(const char *s) {
  while (*s) {
    PutChar(*s++);
  }
}
inline void WriteT(char x) { PutChar(x); }
template <typename T>
inline void WriteT(Number<T> x) {
  if (typeid(T) == typeid(int) || typeid(T) == typeid(long long)) {
    WriteKInt(x.number, x.hex, x.len);
    return;
  }
  if (typeid(T) == typeid(unsigned int) ||
      typeid(T) == typeid(unsigned long long)) {
    WriteKInt(x.number, x.hex, x.len);
    return;
  }
  WriteT("Can't write this type.");
}
template <typename T>
inline void Write(T t) {
  WriteT(t);
}
template <typename T, typename... Args>
void Write(T t, Args... args) {
  WriteT(t);
  Write(args...);
}
inline void Writeln() { PutChar(10); }
template <typename T>
inline void Writeln(T t) {
  WriteT(t);
  PutChar(10);
}
template <typename... Args>
inline void Writeln(Args... args) {
  Write(args...);
  PutChar(10);
}
template <typename... Args>
inline void WriteExit(Args... args) {
  Write(args...);
  PutChar(10);
  exit(0);
}
}  // namespace IO
using namespace IO;
using namespace std;
template <typename T>
inline T Max(T a, T b) {
  return a < b ? b : a;
}
template <typename T, typename... Args>
T Max(T a, Args... args) {
  return Max(a, Max(args...));
}
template <typename T>
inline T Min(T a, T b) {
  return a < b ? a : b;
}
template <typename T, typename... Args>
T Min(T a, Args... args) {
  return Min(a, Min(args...));
}
template <typename T>
inline void Swap(T &a, T &b) {
  register T temp = a;
  a = b;
  b = temp;
}
const long long MOD = 998244353;
inline long long Pow(long long a, long long b, long long mod = MOD) {
  register long long result = 1;
  while (b) {
    if (b & 1) {
      (result *= a) %= mod;
    }
    (a *= a) %= mod;
    b >>= 1;
  }
  return result % mod;
}
const int MAXN = 105;
int n, k;
int s0;
int arr[MAXN];
class Matrix {
 private:
  int len;
  long long m[MAXN][MAXN];

 public:
  inline Matrix(const int len) : len(len) { memset(m, 0, sizeof(m)); }
  inline long long *operator[](const int &place) { return m[place]; }
  inline Matrix operator*(Matrix a) const {
    Matrix result(len);
    for (int i = 0; i <= len; ++i) {
      for (int j = 0; j <= len; ++j) {
        for (int k = 0; k <= len; ++k) {
          result[i][k] += m[i][j] * a[j][k];
          result[i][k] %= MOD;
        }
      }
    }
    return result;
  }
};
inline Matrix Pow(Matrix a, long long b) {
  Matrix result(s0);
  for (int i = 0; i <= s0; ++i) {
    result[i][i] = 1;
  }
  while (b) {
    if (b & 1) {
      result = result * a;
    }
    a = a * a;
    b >>= 1;
  }
  return result;
}
int main() {
  Read(n, k);
  for (int i = 1; i <= n; ++i) {
    Read(arr[i]);
    s0 += arr[i] == 0;
  }
  int t0 = 0;
  for (int i = 1; i <= s0; ++i) {
    t0 += arr[i] == 0;
  }
  Matrix answer(s0);
  Matrix f(s0);
  int low = Max(0, s0 * 2 - n);
  long long q = Pow(1ll * n * (n - 1) / 2, MOD - 2);
  for (int i = low; i <= s0; ++i) {
    if (i ^ low) {
      f[i - 1][i] = i * (n - s0 * 2 + i) * q % MOD;
    }
    if (i ^ s0) {
      f[i + 1][i] = (s0 - i) * (s0 - i) * q % MOD;
    }
    f[i][i] = (1 - i * (n - s0 * 2 + i) * q % MOD -
               (s0 - i) * (s0 - i) * q % MOD + MOD * 2) %
              MOD;
  }
  answer[t0][0] = 1;
  answer = Pow(f, k) * answer;
  Writeln(answer[s0][0]);
  return 0;
}
