#include <bits/stdc++.h>
namespace FastIO {
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
template <class T>
inline bool read(T& x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return false;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
  return true;
}
template <class T, class... U>
bool read(T& h, U&... t) {
  return read(h) && read(t...);
}
};  // namespace FastIO
using namespace std;
using namespace FastIO;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 0x3f3f3f3f;
const long long N = 2e5 + 10;
long long a[N], b[N << 1], n, m;
void add(long long x) {
  for (long long i = x; i < N * 2; i += (i) & (-i)) b[i]++;
}
long long get(long long x) {
  long long ans = 0;
  for (long long i = x; i; i -= (i) & (-i)) ans += b[i];
  return ans;
}
long long solve(long long x) {
  memset(b, 0, sizeof(b));
  long long sum = n + 1;
  long long ans = 0;
  add(sum);
  for (long long i = 1; i <= n; i++) {
    if (a[i] >= x)
      sum++;
    else
      sum--;
    ans += get(sum - 1);
    add(sum);
  }
  return ans;
}
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  cout << solve(m) - solve(m + 1) << endl;
  return 0;
}
