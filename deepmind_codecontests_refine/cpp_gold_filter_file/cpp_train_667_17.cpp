#include <bits/stdc++.h>
using namespace std;
namespace QoE_Library {
namespace QL_Bare_Minimum {
const double PI = 3.141592653589793238460;
const long double E = 2.7182818284590452353;
const long double pi = 10000 * acos(-1.0L);
inline void inpS(char *a) { scanf("%s", a); }
inline int inpLLI(long long int &lld) { return scanf("%lld", &lld); }
inline int inpULLI(unsigned long long int &ulli) {
  return scanf("%llu", &ulli);
}
inline int inpI() {
  int n = 0;
  int ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
  n = n * sign;
  return n;
}
inline void inpI2(int &a, int &b) {
  a = inpI();
  b = inpI();
}
inline void inpI3(int &a, int &b, int &c) {
  a = inpI();
  b = inpI();
  c = inpI();
}
inline double inpD() {
  double res = 0.0;
  char c;
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\n')
      continue;
    else
      break;
  }
  res = c - '0';
  while (1) {
    c = getchar();
    if (c >= '0' && c <= '9')
      res = 10 * res + c - '0';
    else
      break;
  }
  if (c == '.') {
    double decimal = 0.0, divi = 1.0;
    while (1) {
      c = getchar();
      if (c >= '0' && c <= '9')
        decimal += (c - '0') / (divi *= 10.0);
      else
        break;
    }
    res += decimal;
  }
  return res;
}
inline void outpD(double N) {
  char buff[24], sz = 0;
  int integer = N;
  int decimal = (N - integer) * 10000000;
  int tmp = decimal;
  while (decimal) {
    buff[sz++] = '0' + decimal % 10;
    decimal /= 10;
  }
  for (int decimal2 = 1000000; decimal2 > tmp; decimal2 /= 10) {
    buff[sz++] = '0';
  }
  buff[sz++] = '.';
  if (integer == 0) buff[sz++] = '0';
  while (integer) {
    buff[sz++] = '0' + integer % 10;
    integer /= 10;
  }
  while (--sz >= 0) putchar(buff[sz]);
  putchar(10);
}
inline int outpULLI(unsigned long long int u) { return printf("%llu\n", u); }
inline int outpLLI(long long int lli) { return printf("%lld\n", lli); }
inline void outpI(int a) {
  char c;
  char snum[20];
  int i = 0;
  int sign = 0;
  if (a < 0) sign = 1;
  a = abs(a);
  do {
    snum[i++] = a % 10 + 48;
    a = a / 10;
  } while (a != 0);
  i = i - 1;
  if (sign) putchar('-');
  while (i >= 0) putchar(snum[i--]);
  putchar('\n');
}
inline void outpI2(int a, int b) {
  printf("%d ", a);
  outpI(b);
}
inline int outpS(char *s) { return printf("%s\n", s); }
template <typename T1>
void QL_swap(T1 &x, T1 &y) {
  T1 tmp;
  tmp = x;
  x = y;
  y = tmp;
}
template <typename T1>
T1 gcd(T1 a, T1 b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
long double euclideanDist(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) / 1. + (y1 - y2) * (y1 - y2) / 1.);
}
}  // namespace QL_Bare_Minimum
}  // namespace QoE_Library
using namespace QoE_Library::QL_Bare_Minimum;
bool revCmp(int a, int b) { return a > b; }
int main() {
  double n, V, a[100], b[100];
  double d = 1000000000.;
  cin >> n >> V;
  int tot = 0;
  for (int i = (0); i < (n); i = i + (1)) {
    cin >> a[i];
  }
  for (int i = (0); i < (n); i = i + (1)) {
    cin >> b[i];
  }
  for (int i = (0); i < (n); i = i + (1)) {
    tot += a[i];
    d = min(d, b[i] / a[i]);
  }
  cout << setprecision(6) << fixed;
  cout << min(V, d * tot);
}
