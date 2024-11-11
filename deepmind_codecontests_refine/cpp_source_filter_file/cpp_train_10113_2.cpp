#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
static int N, A, B, kmp[MAXN], dp[MAXN];
static string S;
inline void get_kmp(string s) {
  int L = s.length();
  kmp[0] = -1;
  for (int i = 0, j = -1; i < L;) {
    if (j == -1 || s[i] == s[j])
      kmp[++i] = ++j;
    else
      j = kmp[j];
  }
}
inline bool check(int r, int p) {
  get_kmp(S.substr(p, r - p + 1) + '#' + S.substr(0, p));
  for (int i = 1; i <= r + 2; i++)
    if (kmp[i] == r - p + 1) return true;
  return false;
}
int main() {
  static char buffer[MAXN];
  scanf("%d%d%d%s", &N, &A, &B, buffer);
  S = string(buffer);
  for (int i = 0; i < N; i++) {
    int l = 0, r = i, mid, ans = -1;
    while (l <= r) {
      mid = (l + r) / 2;
      if (check(i, mid))
        r = (ans = mid) - 1;
      else
        l = mid + 1;
    }
    dp[i + 1] = dp[i] + A;
    if (ans != -1) dp[i + 1] = min(dp[i + 1], dp[mid] + B);
  }
  printf("%d\n", dp[N]);
  return 0;
}
