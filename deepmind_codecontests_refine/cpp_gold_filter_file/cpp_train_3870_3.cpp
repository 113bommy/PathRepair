#include <bits/stdc++.h>
using namespace std;
int N;
long long K;
string str;
long long DP[105][105];
long long lst[30];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K >> str;
  long long tot = 0;
  for (int i = 0; i <= N; i++) DP[0][i] = 1;
  tot = 1;
  for (int l = 1; l <= N; l++) {
    memset(lst, 0, sizeof(lst));
    for (int i = l; i <= N; i++) {
      int ch = (int)(str[i - 1] - 'a');
      long long num = DP[l - 1][i - 1];
      if (lst[ch]) num -= DP[l - 1][lst[ch] - 1];
      DP[l][i] = min(K, DP[l][i - 1] + num);
      lst[ch] = i;
    }
    tot += DP[l][N];
  }
  if (tot < K) {
    cout << -1 << '\n';
    return 0;
  }
  long long cur = 0;
  long long ans = 0;
  for (int l = N; l >= 0; l--) {
    if (cur + DP[l][N] >= K) {
      ans += (N - l) * (K - cur);
      break;
    }
    ans += DP[l][N] * (N - l);
    cur += DP[l][N];
  }
  cout << ans << '\n';
  return 0;
}
