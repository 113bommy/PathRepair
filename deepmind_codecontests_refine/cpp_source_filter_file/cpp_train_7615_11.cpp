#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, K, t;
  cin >> t;
  for (long i = 0; i < t; i++) {
    cin >> N >> K;
    long Res = 0;
    if (N % K != 0) {
      Res += N % K;
      N -= N % K;
    }
    while (N > 0) {
      N /= K;
      Res++;
      if (N % K != 0) {
        Res += N % K;
        N -= N % K;
      }
    }
    cout << Res << endl;
  }
  return 0;
}
