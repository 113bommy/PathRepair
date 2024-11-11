#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const long long MAXN = 2e5 + 11;
long long N, fac[16], Q, sum;
vector<long long> calc(long long res) {
  vector<long long> Ans;
  Ans.clear();
  set<long long> s;
  set<long long>::iterator it;
  for (long long i = 1; i <= min(N, 15ll); i++) s.insert(i);
  for (long long i = 1; i <= min(N, 15ll); i++) {
    it = s.begin();
    long long x = *it;
    while (res >= fac[min(N, 15ll) - i]) {
      it++;
      res -= fac[min(N, 15ll) - i];
    }
    Ans.push_back(*it);
    s.erase(*it);
  }
  return Ans;
}
signed main() {
  N = read(), Q = read();
  fac[0] = 1;
  for (long long i = 1; i <= 15; i++) fac[i] = fac[i - 1] * i;
  while (Q--) {
    long long opt = read();
    if (opt == 1) {
      long long l = read(), r = read();
      if (N <= 15) {
        vector<long long> Ans = calc(sum);
        long long ss = 0, res = 0;
        for (auto v : Ans) {
          ++ss;
          if (ss >= l && ss <= r) res += v;
        }
        printf("%lld\n", res);
      } else {
        vector<long long> Ans = calc(sum);
        long long ps = N - 15 + 1, res = 0;
        for (auto v : Ans) {
          if (l <= ps && ps <= r) res += v + (N - 15);
          ps++;
        }
        r = min(r, N - 15);
        if (l <= r) res += ((l + r) * (r - l + 1)) / 2;
        printf("%lld\n", res);
      }
    } else
      sum += read();
  }
}
