#include <bits/stdc++.h>
using namespace std;
const long long maxS = 2e5 + 10;
long long MOD = 998244353;
void code_idhr_h() {
  long long N;
  cin >> N;
  long long A[N + 1], pref[N + 1], suf[N + 3];
  pref[0] = 0, suf[N + 1] = 0;
  for (long long i = 1; i <= N; i++) {
    cin >> A[i];
    if (i == 1)
      pref[i] = 1;
    else if (A[i] > A[i - 1])
      pref[i] = pref[i - 1] + 1;
    else
      pref[i] = 1;
  }
  for (long long i = N; i >= 1; i--) {
    if (i == N)
      suf[i] = 1;
    else if (A[i] > A[i - 1])
      suf[i] = suf[i + 1] + 1;
    else
      suf[i] = 1;
  }
  long long ans = 0;
  for (long long i = 1; i <= N; i++) {
    ans = max(ans, max(pref[i], suf[i]));
    if (i == 1)
      ans = max(ans, suf[i + 1] + 1);
    else if (i == N)
      ans = max(ans, pref[i - 1] + 1);
    else {
      ans = max(ans, suf[i + 1] + 1);
      ans = max(ans, pref[i - 1] + 1);
      if (A[i - 1] <= A[i + 1] - 2)
        ans = max(ans, pref[i - 1] + suf[i + 1] + 1);
    }
  }
  cout << ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T = 1;
  for (long long t = 1; t <= T; t++) {
    code_idhr_h();
  }
  return 0;
}
