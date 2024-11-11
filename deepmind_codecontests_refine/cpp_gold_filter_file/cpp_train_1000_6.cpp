#include <bits/stdc++.h>
using namespace std;
const int maxn = 101010;
int a[maxn];
int b[maxn];
int dp[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  int n, k, m;
  cin >> n >> k >> m;
  bool allEqual = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != a[1]) {
      allEqual = 0;
    }
  }
  if (allEqual) {
    cout << (m * 1ll * n) % k;
    return 0;
  }
  if (k >= n) {
    cout << m * 1ll * n;
    return 0;
  }
  int seqLen = 0, ln = 0;
  bool found = 1;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (!ln || a[b[ln]] != a[i]) {
      dp[i] = 1;
    } else {
      dp[i] = dp[b[ln]] + 1;
    }
    if (dp[i] == k) {
      ln -= (k - 1);
    } else {
      b[++ln] = i;
    }
  }
  for (int i = 1; i <= ln; i++) {
    b[i] = a[b[i]];
  }
  int l = 1, r = ln;
  long long ans = ln * 1ll * m;
  while (r - l + 1 >= k && b[l] == b[r]) {
    int i = l, j = r, tmp;
    while (i < j && b[i] == b[r]) {
      i++;
    }
    while (i < j && b[l] == b[j]) {
      j--;
    }
    if ((i == j && b[i] == b[r]) || (i - l) + (r - j) >= k) {
      tmp = k;
      while (tmp && l < i) {
        tmp--;
        l++;
      }
      while (tmp && r > j) {
        tmp--;
        r--;
      }
      if (tmp) {
        r--;
      }
      ans -= (m - 1) * 1ll * k;
    } else {
      break;
    }
  }
  if (r - l + 1 < k) {
    allEqual = 1;
    for (int i = l; i <= r; i++) {
      if (b[i] != b[l]) {
        allEqual = 0;
      }
    }
    if (!allEqual) {
      cout << ans;
      return 0;
    }
    int rem = (r - l + 1) * 1ll * m % k;
    int ln2 = 0;
    for (int i = 1; i < l; i++) {
      a[++ln2] = b[i];
    }
    for (int i = 1; i <= rem; i++) {
      a[++ln2] = b[l];
    }
    for (int i = r + 1; i <= ln; i++) {
      a[++ln2] = b[i];
    }
    bool found = 1;
    int cnt = 0;
    dp[0] = 0;
    ln = 0;
    for (int i = 1; i <= ln2; i++) {
      if (!ln || a[i] != a[b[ln]]) {
        dp[i] = 1;
      } else {
        dp[i] = dp[b[ln]] + 1;
      }
      if (dp[i] == k) {
        ln -= (k - 1);
      } else {
        b[++ln] = i;
      }
    }
    cout << ln;
    return 0;
  }
  cout << ans;
  return 0;
}
