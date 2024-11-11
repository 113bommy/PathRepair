#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> P;
  P.push_back(0);
  for(int i = 0; i < N; i++) {
    ll p;
    cin >> p;
    P.push_back(p);
  }
  P.push_back(N + 1);
  N = A.size();
  vector<ll> dp(N, 1LL << 62);
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    ll acc = 0;
    for(int j = i - 1; j >= 0; j--) {
      if (P[j] < P[i]) {
        dp[i] = min(dp[i], dp[j] + acc);
        acc += B;
      } else {
        acc += A;
      }
    }
  }
  cout << dp.back() << endl;
  return 0;
}
