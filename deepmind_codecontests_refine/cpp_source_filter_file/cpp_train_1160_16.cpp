#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " , ";
  err(++it, args...);
}
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline void read(int &x) {
  char ch;
  while (blank(ch = nc()))
    ;
  if (IOerror) return;
  for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
    ;
}
}  // namespace fastIO
using namespace fastIO;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
long long qp(long long b, long long n) {
  long long r = 1;
  if (n < 0) n += mod - 1;
  b %= mod;
  for (; n; n >>= 1, b = b * b % mod)
    if (n & 1) r = r * b % mod;
  return r;
}
int sgn(double x) {
  if (x < -eps) return -1;
  return x > eps ? 1 : 0;
}
const int maxn = 3e5 + 7;
const int N = 1e5 + 10;
int n;
int sum[N], dif[N], a[N];
pair<int, int> p[N];
int main() {
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[a[i]]++;
    ans += (1LL * a[i] * (n - a[i] + 1));
  }
  for (int i = 1; i <= n; ++i) sum[i] += sum[i - 1];
  for (int i = 1; i < n; ++i) {
    p[i].first = a[i];
    p[i].second = a[i + 1];
    if (p[i].first > p[i].second) swap(p[i].first, p[i].second);
    ans -= 1LL * (p[i].first * (n - p[i].second + 1));
  }
  printf("%lld\n", ans);
}
