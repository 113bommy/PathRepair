#include <bits/stdc++.h>
using namespace std;
static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE* in = stdin;
  char cur = 0;
  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }
  inline void tie(int) {}
  inline explicit operator bool() { return cur != -1; }
  inline static bool is_blank(char c) { return c <= ' '; }
  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }
  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }
  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }
  template <typename T>
  inline FastInput& read_integer(T& n) {
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }
  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(
      T& n) {
    return read_integer(n);
  }
  inline FastInput& operator>>(__int128& n) { return read_integer(n); }
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type
  operator>>(T& n) {
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;
static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE* out = stdout;
  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }
  ~FastOutput() { fwrite(buf, 1, buf_pos, out); }
  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }
  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }
  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int)s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }
  template <typename T>
  inline char* integer_to_string(T n) {
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char)('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }
  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }
  inline char* stringify(__int128 n) { return integer_to_string(n); }
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(
      T n) {
    sprintf(tmp, "%.17f", n);
    return tmp;
  }
  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;
const int mod = 998244353;
const int _ = 1e5 + 5;
inline int add(int a, int b) { return (((a + b) % mod) + mod) % mod; }
inline int mul(int a, int b) { return (((1LL * a * b) % mod) + mod) % mod; }
int n, m;
int a[_], inv[3 * _];
int f[3 * _];
signed main() {
  ios::sync_with_stdio(false);
  fast_input.tie(0);
  int start_time = clock();
  fast_input >> n;
  for (register int i = (1); i <= (n); ++i) fast_input >> a[i];
  for (register int i = (1); i <= (n); ++i) m += a[i];
  inv[1] = 1;
  for (register int i = (2); i <= (m); ++i)
    inv[i] = mul((mod - (mod / i)), inv[mod % i]);
  f[0] = f[1] = 0;
  for (register int i = (1); i <= (m - 1); ++i) {
    int t1 = add(mul(n, i), m);
    t1 = add(t1, -mul(2, i));
    t1 = mul(t1, f[i]);
    int t2 = mul(i, n - 1);
    t2 = mul(-t2, f[i - 1]);
    int t3 = mul(-i, n - 1);
    f[i + 1] = add(add(t1, t2), t3);
    f[i + 1] = mul(f[i + 1], inv[m - i]);
  }
  int ret = 0;
  for (register int i = (1); i <= (m); ++i) ret = add(ret, f[a[i]]);
  ret = add(ret, -f[m]);
  fast_output << ret << '\n';
  return 0;
}
