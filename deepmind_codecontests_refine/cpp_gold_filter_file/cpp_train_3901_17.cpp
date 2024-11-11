#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  long long int N, S, L;
  cin >> N >> S >> L;
  vector<long long int> as(N, 0);
  for (int n = 0; n < N; ++n) cin >> as[n];
  int m = 0;
  multiset<long long int> vs;
  multiset<long long int> xs;
  vector<long long int> dp(N, -1);
  long long int xs_idx = -1;
  for (int n = 0; n < N; ++n) {
    vs.insert(as[n]);
    long long int from = n - L;
    while (S < *vs.rbegin() - *vs.begin()) {
      vs.erase(vs.find(as[m++]));
    }
    if (0 <= from && 0 <= dp[from]) {
      xs.insert(dp[from]);
    }
    while (xs_idx + 2 < m && xs_idx + 1 <= from) {
      xs_idx++;
      if (0 <= xs_idx && 0 <= dp[xs_idx]) xs.erase(xs.find(dp[xs_idx]));
    }
    if (m == 0 && n >= L - 1)
      dp[n] = 1;
    else {
      if (xs.size()) dp[n] = 1 + *xs.begin();
    }
  }
  cout << dp[N - 1] << endl;
  return 0;
}
