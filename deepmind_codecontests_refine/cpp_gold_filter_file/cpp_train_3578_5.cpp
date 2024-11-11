#include <bits/stdc++.h>
using namespace std;
string s;
long long n, memo[11][11][2], ways[11];
long long f(int pos, int ct, bool flag) {
  if (pos == n) {
    if (ct == 0) return 1;
    return 0;
  }
  long long &ret = memo[pos][ct][flag];
  if (ret != -1) return ret;
  ret = 0;
  int d = s[pos] - '0';
  if (flag) {
    for (int i = 0; i < d; ++i) {
      if (i == 4 || i == 7) {
        if (ct - 1 >= 0)
          ret = (ret + f(pos + 1, ct - 1, 1 - flag)) % 1000000007LL;
      } else
        ret = (ret + f(pos + 1, ct, 1 - flag)) % 1000000007LL;
    }
    if (d == 4 || d == 7) {
      if (ct - 1 >= 0) ret = (ret + f(pos + 1, ct - 1, flag)) % 1000000007LL;
    } else
      ret = (ret + f(pos + 1, ct, flag)) % 1000000007LL;
  } else {
    for (int i = 0; i <= 9; ++i) {
      if (i == 4 || i == 7) {
        if (ct - 1 >= 0) ret = (ret + f(pos + 1, ct - 1, flag)) % 1000000007LL;
      } else
        ret = (ret + f(pos + 1, ct, flag)) % 1000000007LL;
    }
  }
  ret = ret % 1000000007LL;
  return ret;
}
long long back(int pos, int sum) {
  if (pos == 0) return 1;
  long long ret = 0LL;
  for (int i = 0; i <= sum; ++i) {
    if (ways[i] == 0) continue;
    long long val = ways[i];
    ways[i]--;
    ret = (ret + (val * back(pos - 1, sum - i)) % 1000000007LL) % 1000000007LL;
    ways[i]++;
  }
  ret = ret % 1000000007LL;
  return ret;
}
int main() {
  cin >> s;
  n = s.length();
  memset(memo, -1, sizeof(memo));
  for (int i = 0; i <= n; ++i) {
    ways[i] = f(0, i, 1);
  }
  ways[0]--;
  long long res = 0LL;
  for (int i = 1; i <= n; ++i) {
    res = (res + back(6, i - 1) * ways[i]) % 1000000007LL;
  }
  cout << res << endl;
}
