#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = INT_MAX;
const long long LLINF = 1000000000000000000LL;
const long long MAX = 200005;
const long long MOD = 998244353;
long long N;
long long X[MAX], Y[MAX];
bool S[MAX];
long long DP[MAX], SDP[MAX];
long long findpos(long long n) {
  long long l, r, mid;
  l = 1;
  r = N;
  while (l < r) {
    mid = (l + r) >> 1;
    if (X[mid] < n) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}
void solve() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i] >> S[i];
  }
  DP[1] = (X[1] - Y[1]) % MOD;
  SDP[1] = DP[1];
  for (int i = 2; i <= N; i++) {
    if (Y[i] > X[i - 1]) {
      DP[i] = (X[i] - Y[i]) % MOD;
    } else {
      long long j = findpos(Y[i]);
      DP[i] = (X[i] - Y[i] + SDP[i - 1] - SDP[j - 1] + 5 * MOD) % MOD;
    }
    SDP[i] = (SDP[i - 1] + DP[i]) % MOD;
  }
  long long ans = X[N] + 1;
  for (int i = 1; i <= N; i++) {
    if (S[i]) {
      ans += DP[i];
      ans %= MOD;
    }
  }
  cout << ans << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
  return 0;
}
