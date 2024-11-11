#include <bits/stdc++.h>
const long double PI = acosl(-1.);
const double eps = 1e-6;
using namespace std;
long long n, rem;
long long dp[52][2][2];
int s[52];
long long f(int pos, int l, int lr) {
  if (dp[pos][l][lr] != -1) return dp[pos][l][lr];
  if (pos == n) {
    if (l && lr) {
      dp[pos][l][lr] = 1;
      return 1;
    } else {
      dp[pos][l][lr] = 0;
      return 0;
    }
  }
  long long ret = 0;
  for (int i = (0); i < (2); ++i) {
    int nl = l;
    int nlr = lr;
    if (i > s[n - 1 - pos])
      nl = 1;
    else if (i < s[n - 1 - pos])
      nl = 0;
    if (1 - i > s[n - 1 - pos])
      nlr = 1;
    else if (1 - i < s[n - 1 - pos])
      nlr = 0;
    ret += f(pos + 1, nl, nlr);
  }
  dp[pos][l][lr] = ret;
  return ret;
}
int main() {
  cin >> n >> rem;
  ++rem;
  int npre = n / 2 + n % 2;
  bool found = false;
  memset((dp), -1, sizeof((dp)));
  memset((s), 0, sizeof((s)));
  for (int pre = 0; pre < (1 << (npre - 1)); pre++) {
    if (pre > 0) {
      int i = npre - 1;
      while (i >= 0) {
        if (s[i] == 0) {
          s[i] = 1;
          break;
        }
        s[i] = 0;
        --i;
      }
      for (int j = npre; j <= n - i - 1; j++) {
        dp[j][0][0] = -1;
        dp[j][0][1] = -1;
        dp[j][1][0] = -1;
        dp[j][1][1] = -1;
      }
    }
    int less = 1;
    int lessrev = 1;
    if (n % 2 == 1 && s[npre - 1] == 1) lessrev = 0;
    long long temp = f(npre, less, lessrev);
    if (temp < rem)
      rem -= temp;
    else {
      found = true;
      break;
    }
  }
  if (!found) {
    cout << -1 << endl;
    return 0;
  }
  int less = 1;
  int lessrev = 1;
  if (n % 2 == 1 && s[npre - 1] == 1) lessrev = 0;
  for (int i = npre; i < n; i++) {
    int nl = less;
    int nlr = lessrev;
    if (0 < s[n - 1 - i]) nl = 0;
    if (1 < s[n - 1 - i]) nlr = 0;
    long long temp = f(i + 1, nl, nlr);
    if (temp >= rem) {
      s[i] = 0;
      less = nl;
      lessrev = nlr;
      continue;
    }
    rem -= temp;
    s[i] = 1;
    if (1 > s[n - 1 - i]) less = 1;
    if (0 < s[n - 1 - i]) lessrev = 0;
  }
  for (int i = 0; i < n; i++) cout << s[i];
  printf("\n");
  return 0;
}
