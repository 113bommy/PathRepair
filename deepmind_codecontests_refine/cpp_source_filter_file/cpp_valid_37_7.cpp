#include <bits/stdc++.h>
using namespace std;
void dbg() { std::cout << "  #\n"; }
template <typename T, typename... Args>
void dbg(T a, Args... args) {
  std::cout << a << ' ';
  dbg(args...);
}
const long long maxn = 2e5 + 10;
const long long MAX = 1000;
const long long inf = 0x3f3f3f3f;
const long long mod = 998244353;
long long n, m;
long long a[maxn];
long long f[maxn];
long long ans[maxn];
vector<long long> A[maxn];
long long getint() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  long long x = ch - 48;
  while (isdigit(ch = getchar())) x = x * 10 + ch - 48;
  return x;
}
bool isok;
void dfs(long long now, long long fa, long long k) {
  for (auto to : A[now])
    if (to != fa) {
      dfs(to, now, k);
    }
  if (a[now] % k == 0) {
    a[fa]++;
  } else {
    if (fa != 0) {
      a[now]++;
      if (a[now] % k != 0) {
        isok = false;
      }
    }
  }
}
void solve() {
  n = getint();
  for (long long i = (1); i <= (n); ++i) ans[i] = 0, A[i].clear();
  for (long long i = (1); i <= (n - 1); ++i) {
    long long x, y;
    x = getint();
    y = getint();
    A[x].push_back(y);
    A[y].push_back(x);
  }
  ans[1] = 1;
  for (long long i = (1); i <= (n - 1); ++i) ans[1] = (ans[1] * 2ll % mod);
  for (long long i = (2); i <= (n); ++i)
    if ((n - 1) % i == 0) {
      for (long long j = (1); j <= (n); ++j) a[j] = 0;
      isok = 1;
      dfs(1, 0, i);
      if (isok) ans[i]++;
    }
  for (long long i = (1); i <= (n); ++i) {
    long long j = i + i;
    while (j <= n) {
      ans[i] -= ans[j];
      ans[i] = (ans[i] + mod) % mod;
      j = j + i;
    }
  }
  for (long long i = (1); i <= (n); ++i) printf("%d ", ans[i] % mod);
  printf("\n");
}
signed main() {
  long long TestCase = 1;
  cin >> TestCase;
  while (TestCase--) {
    solve();
  }
  char EndFile = getchar();
  EndFile = getchar();
  return 0;
}
