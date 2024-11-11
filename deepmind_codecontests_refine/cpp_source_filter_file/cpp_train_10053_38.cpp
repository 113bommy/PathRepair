#include <bits/stdc++.h>
using namespace std;
namespace Fastio {
enum io_flags {
  ignore_int = 1 << 0,
  char_enter = 1 << 1,
  flush_stdout = 1 << 2,
  flush_stderr = 1 << 3,
  endline = char_enter | flush_stdout
};
enum number_type_flags {
  output_double_stable = 1 << 0,
  output_double_faster = 1 << 1
};
struct Reader {
  char endch;
  Reader() { endch = '\0'; }
  Reader& operator>>(io_flags f) {
    if (f & ignore_int) {
      endch = getchar();
      while ((!isdigit(endch)) && endch != '-' && endch != EOF)
        endch = getchar();
      while (isdigit(endch = getchar()))
        ;
    }
    return *this;
  }
  Reader& operator>>(char& ch) {
    ch = getchar();
    while (ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t') ch = getchar();
    return *this;
  }
  Reader& operator>>(double& lf) {
    bool flag = 0;
    endch = getchar();
    while ((!isdigit(endch)) && endch != '-' && endch != EOF) endch = getchar();
    if (endch == '-') flag = 1, endch = getchar();
    lf = endch & 15;
    while (isdigit(endch = getchar())) lf = lf * 10 + (endch & 15);
    if (endch == '.') {
      double digit = 0.1;
      while (isdigit(endch = getchar())) {
        lf += (endch & 15) * digit;
        digit *= 0.1;
      }
    }
    if (flag) lf = -lf;
    return *this;
  }
  template <typename Int>
  Reader& operator>>(Int& d) {
    bool flag = 0;
    endch = getchar();
    while ((!isdigit(endch)) && endch != '-' && endch != EOF) endch = getchar();
    if (endch == '-') flag = 1, endch = getchar();
    d = endch & 15;
    while (isdigit(endch = getchar())) d = (d << 3) + (d << 1) + (endch & 15);
    if (flag) d = -d;
    return *this;
  }
  template <typename Int>
  inline Int get() {
    bool flag = 0;
    endch = getchar();
    while ((!isdigit(endch)) && endch != '-' && endch != EOF) endch = getchar();
    if (endch == '-') flag = 1, endch = getchar();
    Int d = endch & 15;
    while (isdigit(endch = getchar())) d = (d << 3) + (d << 1) + (endch & 15);
    if (flag) d = -d;
    return d;
  }
} read;
struct Writer {
  Writer& operator<<(io_flags f) {
    if (f & char_enter) putchar(10);
    if (f & flush_stdout) fflush(stdout);
    if (f & flush_stderr) fflush(stderr);
    return *this;
  }
  Writer& operator<<(const char* ch) {
    while (*ch) putchar(*(ch++));
    return *this;
  }
  Writer& operator<<(const char ch) {
    putchar(ch);
    return *this;
  }
  template <typename Int>
  Writer& operator<<(Int x) {
    static char buffer[33];
    static int top = 0;
    if (!x) {
      putchar('0');
      return *this;
    }
    if (x < 0) putchar('-'), x = ~x + 1;
    while (x) {
      buffer[++top] = '0' | (x % 10);
      x /= 10;
    }
    while (top) putchar(buffer[top--]);
    return *this;
  }
  inline void operator()(double val, int eps_digit = 6, char endch = '\0',
                         number_type_flags flg = output_double_faster) {
    if (flg & output_double_stable) {
      static char output_format[10];
      sprintf(output_format, "%%.%dlf", eps_digit);
      printf(output_format, val);
    } else if (flg & output_double_faster) {
      if (val < 0) {
        putchar('-');
        val = -val;
      }
      double eps_number = 0.5;
      for (int i = 1; i <= eps_digit; i++) eps_number /= 10;
      val += eps_number;
      (*this) << (long long)val;
      val -= (long long)val;
      putchar('.');
      while (eps_digit--) {
        val *= 10;
        putchar((int)val | '0');
        val -= (int)val;
      }
    } else {
      (*this) << "1.#ERROR_NOT_IDENTIFIED_FLAG";
    }
    if (endch) putchar(endch);
  }
} write;
}  // namespace Fastio
using namespace Fastio;
namespace File_IO {
void init_IO() {
  freopen("Gosha is hunting.in", "r", stdin);
  freopen("Gosha is hunting.out", "w", stdout);
}
}  // namespace File_IO
const int N = 2e3 + 7, BinarySearchTime = 36;
int n, a, b;
double p1[N], p2[N];
struct dp_element {
  double val;
  int a_used, b_used;
  dp_element() {}
  dp_element(double V, int A, int B) : val(V), a_used(A), b_used(B) {}
  dp_element operator+(const dp_element b) const {
    return dp_element(val + b.val, a_used + b.a_used, b_used + b.b_used);
  }
  bool operator<(const dp_element b) const { return val < b.val; }
};
dp_element f[N];
dp_element check_dp(double x, double y) {
  f[0] = dp_element(0, 0, 0);
  for (int i = 1; i <= n; i++) {
    f[i] = max(max(f[i - 1], f[i - 1] + dp_element(p1[i] - x, 1, 0)),
               max(f[i - 1] + dp_element(p2[i] - y, 0, 1),
                   f[i - 1] + dp_element(p1[i] + p2[i] - p1[i] * p2[i] - x - y,
                                         1, 1)));
  }
  return f[n];
}
pair<dp_element, double> check_p2(double x_dif) {
  double l = 0, r = 1, mid;
  for (int i = 0; i <= BinarySearchTime; i++) {
    mid = (l + r) / 2;
    if (check_dp(x_dif, mid).b_used >= b)
      l = mid;
    else
      r = mid;
  }
  double ans = (l + r) / 2;
  return make_pair(check_dp(x_dif, ans), ans);
}
double check_p1() {
  double l = 0, r = 1, mid;
  for (int i = 0; i <= BinarySearchTime; i++) {
    mid = (l + r) / 2;
    if (check_p2(mid).first.a_used >= a)
      l = mid;
    else
      r = mid;
  }
  double ans = (l + r) / 2;
  pair<dp_element, double> ret = check_p2(ans);
  return ret.first.val + a * ans + b * ret.second;
}
signed main() {
  read >> n >> a >> b;
  for (int i = 1; i <= n; i++) read >> p1[i];
  for (int i = 1; i <= n; i++) read >> p2[i];
  write(check_p1(), 6, '\n', output_double_stable);
  return 0;
}
