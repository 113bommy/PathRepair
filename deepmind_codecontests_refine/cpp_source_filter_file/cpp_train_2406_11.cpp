#include <bits/stdc++.h>
using namespace std;
string a, l, r;
int leftMatch[1000013], rightMatch[1000013];
int n;
long long dp[1000013];
long long sum[1000013];
void build(string b, string a, int* z) {
  string s = b + '$' + a;
  int l = 0, r = 0, n = s.size();
  for (int i = 1; i < n; i++) {
    if (i > r) {
      l = r = i;
      while (s[r] == s[r - l]) r++;
      z[i] = r - l;
      r--;
    } else {
      if (z[i - l] < r - i + 1) {
        z[i] = z[i - l];
      } else {
        l = i;
        while (s[r] == s[r - l]) r++;
        z[i] = r - l;
        r--;
      }
    }
  }
}
int main() {
  if (fopen("FILENAME.in", "r")) {
    freopen("FILENAME.in", "r", stdin);
    freopen("FILENAME.out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> l >> r;
  n = a.size();
  build(l, a, leftMatch);
  build(r, a, rightMatch);
  for (int i = 0; i < n; i++) {
    leftMatch[i] = leftMatch[i + l.size() + 1];
  }
  for (int i = 0; i < n; i++) {
    rightMatch[i] = rightMatch[i + r.size() + 1];
  }
  string s = a;
  dp[0] = 1;
  sum[1] = 1;
  for (int i = 1; i <= n; i++) {
    int leftIndex = i - l.size();
    if (leftIndex >= 0) {
      int leftDifference = leftMatch[leftIndex];
      if (leftDifference == l.size()) {
      } else {
        bool greater = s[leftIndex + leftDifference] > l[leftDifference];
        if (greater) {
        } else {
          leftIndex--;
        }
      }
    } else {
      leftIndex = -1;
    }
    int rightIndex = i - r.size();
    if (rightIndex >= 0) {
      int rightDifference = rightMatch[rightIndex];
      if (rightDifference == r.size()) {
      } else {
        bool greater = s[rightIndex + rightDifference] > r[rightDifference];
        if (greater) {
          rightIndex++;
        }
      }
    } else {
      rightIndex = 0;
    }
    if (l[0] == '0' && l.size() == 1 && leftIndex == i - 1 && leftIndex >= 0 &&
        s[i - 1] == '0') {
      dp[i] += dp[i - 1];
    }
    dp[i] +=
        (((sum[leftIndex + 1] - sum[rightIndex]) % 998244353LL) + 998244353LL) %
        998244353LL;
    dp[i] %= 998244353LL;
    sum[i + 1] = (sum[i] + ((i != n && s[i] == '0') ? 0 : dp[i])) % 998244353LL;
  }
  cout << dp[n] << endl;
}
