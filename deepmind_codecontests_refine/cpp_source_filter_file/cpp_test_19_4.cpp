#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll inf = 1000000000;
const ll INF = 1e9;
void pline(vector<ll> lis) {
  for (ll(i) = (0); (i) < (lis.size()); (i)++) {
    printf("%lld", lis[i]);
    if (i != lis.size() - 1)
      printf(" ");
    else
      printf("\n");
  }
}
int main() {
  ll TT;
  scanf("%lld", &TT);
  for (ll(loop) = (0); (loop) < (TT); (loop)++) {
    ll N, n;
    scanf("%lld", &N);
    n = N;
    vector<ll> a(N);
    for (ll(i) = (0); (i) < (N); (i)++) {
      scanf("%lld", &a[i]);
    }
    vector<ll> dp(1001, INF);
    vector<ll> ndp(1001, INF);
    dp[0] = 0;
    for (ll(i) = (0); (i) < (n); (i)++) {
      ll na = a[i];
      for (ll(j) = (0); (j) < (1001); (j)++) ndp[j] = INF;
      for (ll(l) = (0); (l) < (1001); (l)++) {
        {
          ll nexd, nexl;
          if (l - na < 0) {
            nexl = 0;
            nexd = dp[l] + (na - l);
          } else {
            nexl = l - na;
            nexd = dp[l];
          }
          if (0 <= nexl && nexl <= 1000) {
            ndp[nexl] = min(ndp[nexl], nexd);
          }
        }
        {
          if (l + na > 1000) continue;
          ndp[l + na] = min(ndp[l + na], max(dp[l], l + na));
        }
      }
      swap(dp, ndp);
    }
    ll ans = INF;
    for (ll(i) = (0); (i) < (1001); (i)++) {
      ans = min(ans, dp[i]);
    }
    printf("%lld\n", ans);
  }
}
