#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int MAXK = (int)1e6;
const int MAXA = 1000;
int N, K;
int A[MAXK];
bitset<1000 + 1> dp[2];
signed main() {
  ios::sync_with_stdio(0);
  {
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
      cin >> A[i];
    }
    sort(A, A + K);
    K = unique(A, A + K) - A;
  }
  {
    int offset = N;
    dp[0][offset] = 1;
    for (int i = 0; i < 1000; ++i) {
      dp[~i & 1].reset();
      for (int j = 0; j < K; ++j) {
        int t = A[j] - N;
        if (t >= 0) {
          dp[~i & 1] |= dp[i & 1] << t;
        } else {
          dp[~i & 1] |= dp[i & 1] >> -t;
        }
      }
      if (dp[~i & 1][offset]) {
        cout << i + 1 << endl;
        exit(0);
      }
    }
    cout << -1 << endl;
  }
  return 0;
}
