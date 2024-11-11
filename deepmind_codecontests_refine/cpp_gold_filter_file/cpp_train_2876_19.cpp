#include <bits/stdc++.h>
using namespace std;
namespace mine {
long long qread() {
  long long ans = 0, f = 1;
  char c = getchar();
  while (c < '0' or c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c and c <= '9') ans = ans * 10 + c - '0', c = getchar();
  return ans * f;
}
void write(long long num) {
  if (num < 0) putchar('-'), num = -num;
  if (num >= 10) write(num / 10);
  putchar('0' + num % 10);
}
void write1(long long num) {
  write(num);
  putchar(' ');
}
void write2(long long num) {
  write(num);
  putchar('\n');
}
template <typename T>
void chmax(T &x, const T y) {
  x = (x > y ? x : y);
}
template <typename T>
void chmin(T &x, const T y) {
  x = (x < y ? x : y);
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int mm(const int x) { return x >= MOD ? x - MOD : x; }
template <typename T>
void add(T &x, const int &y) {
  x = (x + y >= MOD ? x + y - MOD : x + y);
}
long long qpower(long long x, long long e, int mod = MOD) {
  long long ans = 1;
  if (e < 0) {
    puts("error");
    exit(666);
  }
  while (e) {
    if (e & 1) ans = ans * x % mod;
    x = x * x % mod;
    e >>= 1;
  }
  return ans;
}
long long invm(long long x) { return qpower(x, MOD - 2); }
const int N = 1e6 + 10;
const long long MXNUM = 2e9;
long long val[N], bin[N];
pair<int, int> sta[N];
int top;
long long sum[N];
long long a[N], b[N];
long long getnum(int l, int r) {
  return (b[l] + MOD - b[r + 1] * bin[r - l + 1] % MOD) * 2 % MOD;
}
vector<pair<int, int> > qes[N];
int ans[N];
void main() {
  int n = qread(), q = qread();
  for (int i = (1), I = (n); i <= I; i++) a[i] = qread();
  bin[0] = 1;
  for (int i = (1), I = (n); i <= I; i++) bin[i] = bin[i - 1] * 2 % MOD;
  for (int i = (n), I = (1); i >= I; i--)
    b[i] = (b[i + 1] * 2 + MOD + a[i]) % MOD;
  for (int i = (1), I = (q); i <= I; i++) {
    int l = qread(), r = qread();
    qes[r].push_back(make_pair(l, i));
    if (r == 1) ans[i] = a[1];
  }
  for (int r = (2), I = (n); r <= I; r++) {
    sta[++top] = make_pair(r, r);
    val[top] = a[r] * 2;
    while (top > 1 and val[top] >= 0) {
      int ln = sta[top - 1].second - sta[top - 1].first + 1;
      if ((ln > 31 and val[top] > 0) or
          (val[top - 1] + (val[top] << ln) > MXNUM))
        val[top - 1] = MXNUM;
      else
        val[top - 1] = val[top - 1] + (val[top] << ln);
      top--;
      sta[top].second = r;
    }
    sum[top] = (sum[top - 1] + val[top]) % MOD;
    for (auto qq : qes[r]) {
      int l = qq.first, id = qq.second,
          pos = upper_bound(sta + 1, sta + top + 1, make_pair(l + 1, INF)) -
                sta - 1;
      ans[id] =
          (sum[top] - sum[pos] + getnum(l + 1, sta[pos].second) + a[l]) % MOD;
    }
  }
  for (int i = (1), I = (q); i <= I; i++) write2((ans[i] + MOD) % MOD);
}
};  // namespace mine
signed main() {
  srand(time(0));
  mine::main();
}
