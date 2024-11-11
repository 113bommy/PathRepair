#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, K;
  string S, ans = "";
  cin >> N >> K;
  cin >> S;
  for (long long i = 0; i < N; i++) ans += S[i % K];
  if (ans >= S) {
    cout << N << "\n" << ans;
    return 0;
  }
  for (long long i = K - 1; i >= 0; i--) {
    if (S[i] == '9')
      S[i] = '0';
    else {
      S[i] = S[i]++;
      break;
    }
  }
  for (long long i = 0; i < N; i++) ans[i] = S[i % K];
  cout << N << "\n" << ans;
}
