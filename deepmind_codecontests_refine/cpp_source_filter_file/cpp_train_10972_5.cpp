#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long N, M, K, sol;
long long mpow(long long a, long long b) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b /= 2;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;
  long long lft = N - M;
  long long top = N / K;
  long long cnt = max(0ll, top - lft);
  sol = M - cnt * K;
  sol += 2 * K * (mpow(2, cnt) - 1);
  sol %= MOD;
  if (sol < 0) sol += MOD;
  cout << sol << endl;
}
