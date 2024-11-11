#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll N;
  cin >> N;
  ll A[1LL << 18];
  REP(i, 0, 1LL << N) scanf("%lld", A + i);

  ll ans = 0;
  REP(k, 1, 1LL << N) {
    ll p = 0, q = 0;
    ll i = k;
    do {
      ll x = max(max(p, q), A[i]);
      q = p + q + A[i] - w - min(min(p, q), A[i]);
      p = w;
      i = (i - 1) & k;
    } while(i != k);
    ans = max(ans, p + q);
    printf("%lld\n", ans);
  }
}