#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  int L, n, m, k = 1;
  cin >> n >> m >> S;
  L = S.length();
  for (int i = 0; i < L - 1; i++) {
    if (S[i] != S[i + 1]) {
      k++;
    }
  }
  long long ans = k * 1LL * (1LL * n * m - n);
  long long cnt = 1;
  for (int i = 1; i < L; i++) {
    if (S[i] != S[i - 1] && (i == 1 || S[i - 2] == S[i])) {
      cnt++;
    } else {
      ans -= cnt * (cnt - 1) / 2;
      if (S[i] == S[i - 1])
        cnt = 1;
      else
        cnt = 2;
    }
  }
  ans -= cnt * (cnt - 1) / 2;
  cout << ans << endl;
}
