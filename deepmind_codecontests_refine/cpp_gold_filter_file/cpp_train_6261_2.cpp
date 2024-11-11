#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  char c = getchar();
  long long flag = 0;
  while (c < '0' || c > '9') flag |= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
long long max(long long a, long long b) { return (a > b ? a : b); }
long long min(long long a, long long b) { return (a < b ? a : b); }
bool checkmin(long long &a, long long b) { return (b < a ? a = b, 1 : 0); }
bool checkmax(long long &a, long long b) { return (b > a ? a = b, 1 : 0); }
const long long N = 500005;
const long long p = 131;
const long long mod1 = 19260817;
const long long mod2 = 999983;
const long long inf = 100000000000;
long long n, m, tot[3], f[3];
char s[N], t[N];
pair<long long, long long> Hash[N], Bit[N];
void get_hash() {
  Bit[0] = make_pair(1, 1);
  Hash[0] = make_pair(0, 0);
  for (long long i = 1; i <= m; ++i) {
    Bit[i] =
        make_pair(Bit[i - 1].first * p % mod1, Bit[i - 1].second * p % mod2);
    Hash[i].first = (Hash[i - 1].first * p % mod1 + t[i]) % mod1;
    Hash[i].second = (Hash[i - 1].second * p % mod2 + t[i]) % mod2;
  }
}
pair<long long, long long> range(long long l, long long r) {
  return make_pair(
      ((Hash[r].first - Hash[l - 1].first * Bit[r - l + 1].first) % mod1 +
       mod1) %
          mod1,
      ((Hash[r].second - Hash[l - 1].second * Bit[r - l + 1].second) % mod2 +
       mod2) %
          mod2);
}
void init() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1), m = strlen(t + 1);
  get_hash();
  for (long long i = 1; i <= n; ++i) {
    tot[s[i] - '0']++;
  }
  for (long long i = 1; i <= m; ++i) {
    f[t[i] - '0']++;
  }
}
void solve() {
  if (f[0] > tot[0] || f[1] > tot[1]) {
    printf("%s\n", s + 1);
    return;
  }
  tot[0] -= f[0], tot[1] -= f[1];
  long long max_len = 0;
  for (long long i = 1; i < m; ++i) {
    if (range(1, i) == range(m - i + 1, m)) {
      max_len = i;
    }
  }
  long long res = m - max_len;
  f[0] = f[1] = 0;
  for (long long i = 1; i <= res; ++i) {
    f[t[i] - 48]++;
  }
  long long count =
      min((f[0] == 0 ? inf : tot[0] / f[0]), (f[1] == 0 ? inf : tot[1] / f[1]));
  tot[0] -= f[0] * count, tot[1] -= f[1] * count;
  printf("%s", t + 1);
  for (long long i = 1; i <= count; ++i) {
    printf("%s", t + max_len + 1);
  }
  for (long long i = 1; i <= tot[0]; ++i) printf("0");
  for (long long i = 1; i <= tot[1]; ++i) printf("1");
  printf("\n");
}
int main() {
  init();
  solve();
  return 0;
}
