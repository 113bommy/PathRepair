#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3", "sse2", "sse")
#pragma GCC target("avx", "sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
#pragma GCC push_options
#pragma GCC pop_options
#pragma GCC reset_options
#pragma GCC optimize("O3")
const double eps = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const long long LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const long long MOD = 1000000007;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const double PI = 3.141592653589793;
inline void fastll(long long &input_number) {
  input_number = 0;
  int ch = getchar_unlocked();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar_unlocked();
  }
  while (ch >= '0' && ch <= '9') {
    input_number = (input_number << 3) + (input_number << 1) + ch - '0';
    ch = getchar_unlocked();
  }
  input_number *= sign;
}
inline void open(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}
inline void fasterios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long n;
long long tmpans;
long long lst, ans;
long long cnt[1000005];
long long fact[1000005];
long long expo(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = expo(a, b / 2);
  tmp = (tmp * tmp) % MOD;
  if (b & 1) tmp = (tmp * a) % MOD;
  return tmp;
}
long long get(long long now, long long step, long long divstep) {
  long long cur = 0;
  for (int i = now; i <= n; i += now) {
    if (cnt[i] == 0) cur++;
    cnt[i]++;
  }
  long long nx = 0;
  if (now != 1) {
    if (step == divstep) {
      nx = get(now / 3, step + 1, divstep);
    } else {
      nx = get(now / 2, step + 1, divstep);
    }
  }
  for (int i = now; i <= n; i += now) cnt[i]--;
  tmpans = (tmpans * fact[cur]) % MOD;
  tmpans = (tmpans * fact[cur - 1 + nx]) % MOD;
  tmpans = (tmpans * expo(fact[cur - 1], MOD - 2)) % MOD;
  tmpans = (tmpans * expo(fact[nx], MOD - 2)) % MOD;
  return cur + nx;
}
int main() {
  cin >> n;
  fact[0] = 1;
  for (int i = 1; i <= 1000000; i++) fact[i] = (fact[i - 1] * i) % MOD;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  long long lst, lstb;
  for (int i = 0; i <= 1000; i++) {
    if ((1LL << i) > n) break;
    lst = (1LL << i);
    lstb = i;
  }
  tmpans = 1;
  get(lst, 1, 0);
  ans += tmpans;
  if ((lst / 2) * 3 <= n) {
    for (int i = 1; i <= lstb; i++) {
      tmpans = 1;
      get((lst / 2) * 3, 1, i);
      ans += tmpans;
    }
  }
  cout << ans % MOD << '\n';
  return 0;
}
