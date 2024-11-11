#include <bits/stdc++.h>
using namespace std;
int len;
char s[1000010];
int sum[1000010];
int last, last2, num, wei;
int next_dog[1000010];
int next_gutou[1000010];
int inf = 2e8;
int dp[1000010];
bool check(int w) {
  dp[0] = s[1] == '*' ? 1 : next_gutou[1];
  int q = 0, last = 0;
  for (int i = 1; i <= len; i++)
    if (s[i] == 'P') {
      ++q;
      if (dp[q - 1] < i) {
        if (i - w > dp[q - 1]) return 0;
        dp[q] = next_gutou[i];
        if (q >= 2 && i - w <= dp[q - 2]) {
          int A = last + w;
          if (A >= len)
            dp[q] = len + 1;
          else
            dp[q] = max(dp[q], next_gutou[A + 1]);
        }
      } else {
        if (i + w >= len)
          dp[q] = len + 1;
        else
          dp[q] = next_gutou[i + w];
      }
      last = i;
    }
  return dp[q] == len + 1;
}
int main() {
  scanf("%d", &len);
  scanf("%s", &s[1]);
  for (int i = 1; i <= len; i++) {
    sum[i] = sum[i - 1];
    if (s[i] == '*') sum[i]++;
  }
  last = last2 = len + 1;
  for (int i = len; i >= 1; i--) {
    next_gutou[i] = last2;
    if (s[i] == 'P')
      next_dog[i] = last, last = i, num++, wei = i;
    else if (s[i] == '*')
      last2 = i;
  }
  if (num == 1) {
    int A = sum[wei - 1], B = sum[len] - sum[wei];
    if (A < B) {
      cout << B << ' ';
      int T = 0;
      for (int i = len; i >= 1; i--)
        if (s[i] == '*') {
          T = i;
          break;
        }
      cout << T - wei;
    } else if (A > B) {
      cout << A << " ";
      int T = 0;
      for (int i = 1; i <= wei; i++)
        if (s[i] == '*') {
          T = i;
          break;
        }
      cout << wei - T;
    } else {
      cout << A << " ";
      if (!A)
        cout << 0 << '\n';
      else {
        int AA, BB;
        for (int i = 1; i <= len; i++)
          if (s[i] == '*') {
            A = i;
            break;
          }
        for (int i = len; i >= 1; i--)
          if (s[i] == '*') {
            B = i;
            break;
          }
        cout << min(wei - A, B - wei);
      }
    }
  } else {
    cout << sum[len] << " ";
    int l = 0, r = inf;
    int ans;
    while (l <= r) {
      int mid = l + r >> 1;
      if (check(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    cout << ans;
  }
  return 0;
}
