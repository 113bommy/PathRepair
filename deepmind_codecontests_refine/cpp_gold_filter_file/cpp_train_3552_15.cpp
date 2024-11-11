#include <bits/stdc++.h>
using namespace std;
char str[260][260];
int cnt[260][26];
int odd[260];
long long h[260];
long long val[260];
int dp[260];
int count(int l, int r) {
  int size = r - l + 1;
  int ans = 0;
  int rr = 0;
  int p = 0;
  for (int i = 1; i <= size; i++) {
    if (i <= rr)
      dp[i] = min(dp[2 * p - i], rr - i);
    else
      dp[i] = 0;
    while (i - dp[i] > 0 && i + dp[i] <= size &&
           h[l + i - 1 - dp[i]] == h[l + i - 1 + dp[i]])
      dp[i]++;
    if (rr < i + dp[i]) {
      rr = i + dp[i];
      p = i;
    }
    ans += dp[i];
  }
  rr = 0;
  p = 0;
  for (int i = 1; i <= size; i++) {
    if (i <= rr)
      dp[i] = min(dp[2 * p - i], rr - i);
    else
      dp[i] = 0;
    while (i - dp[i] > 0 && i + dp[i] + 1 <= size &&
           h[l + i - 1 - dp[i]] == h[l + i + dp[i]])
      dp[i]++;
    if (rr < i + dp[i]) {
      rr = i + dp[i];
      p = i;
    }
    ans += dp[i];
  }
  return ans;
}
int main(void) {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> str[i];
  mt19937_64 mrand(
      chrono::high_resolution_clock::now().time_since_epoch().count());
  long long mod = (1LL << 61) - 1;
  for (int i = 0; i < 26; i++) val[i] = mrand() & mod;
  long long ans = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      odd[j] = 0;
      h[j] = 0;
      for (int k = 0; k < 26; k++) cnt[j][k] = 0;
    }
    for (int j = i; j < M; j++) {
      for (int k = 0; k < N; k++) {
        int x = str[k][j] - 'a';
        h[k] += val[x];
        h[k] %= mod;
        cnt[k][x]++;
        if (cnt[k][x] % 2)
          odd[k]++;
        else
          odd[k]--;
      }
      int idx1 = 0;
      while (idx1 < N) {
        if (odd[idx1] > 1) {
          idx1++;
          continue;
        }
        int idx2 = idx1;
        while (idx2 < N && odd[idx2] < 2) idx2++;
        idx2--;
        ans += count(idx1, idx2);
        idx1 = idx2 + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
