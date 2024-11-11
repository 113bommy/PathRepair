#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    long long N, K;
    cin >> N >> K;
    int step = 0;
    while (N > 0) {
      if (N % K == 0) {
        N /= K;
        ++step;
      } else {
        long long newN = N / K * K;
        step += N - newN;
        N = newN;
      }
    }
    cout << step << endl;
  }
  return 0;
}
