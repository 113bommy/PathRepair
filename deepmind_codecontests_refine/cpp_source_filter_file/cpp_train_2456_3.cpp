#include <bits/stdc++.h>
inline void in(int &MAGNUS) { scanf("%d", &MAGNUS); }
inline void out(int MAGNUS) { printf("%d\n", MAGNUS); }
inline void in(int &MAGNUS, int &CLAR) { scanf("%d%d", &MAGNUS, &CLAR); }
inline void out(int MAGNUS, int CLAR) { printf("%d %d\n", MAGNUS, CLAR); }
inline void inl(long long &LIV) { scanf("%lld", &LIV); }
inline void inl(long long &LIV, long long &MART) {
  scanf("%lld%lld", &LIV, &MART);
}
inline void outl(long long LIV) { printf("%lld\n", LIV); }
inline void outl(long long LIV, long long MART) {
  printf("%lld %lld\n", LIV, MART);
}
using namespace std;
long long x[100005];
int main() {
  long long N, K;
  inl(N, K);
  long long mn = (1LL << 60);
  for (int i = 1; i <= N; i++) {
    inl(x[i]);
    if (x[i] % K != 0) {
      out(-1);
      return 0;
    }
    mn = min(mn, x[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += (x[i] - mn) / K;
  }
  outl(ans);
  return 0;
}
