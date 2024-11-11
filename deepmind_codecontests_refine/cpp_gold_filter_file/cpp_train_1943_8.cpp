#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 17;
const int inf = 1e9;
const int N = 1e3 + 5;
int t, k, dp[N][2], dp2[N][N * 2];
char s[N];
string str;
int f(int left, int ctr) {
  if (!left) return ctr;
  int &r = dp[left][ctr];
  if (r != -1) return r;
  r = 0;
  int t = 1;
  for (int i = left - 1; i >= 1; i--) {
    r = (r + 2LL * f(i, ctr | ((left - i) <= k)) * (long long)t % mod) % mod;
    t = (t * 8LL) % mod;
  }
  return r = (r + f(0, ctr) * (long long)t % mod);
}
int ctr(string &str) {
  int last = -1, cur = 0;
  for (__typeof(str.begin()) it = str.begin(); it != str.end(); it++) {
    if (*it == '7' || *it == '4') {
      if (last != -1 && cur - last <= k) return cur;
      last = cur;
    }
    cur++;
  }
  return inf;
}
int f2(int left, int t) {
  if (left == 0) return 0;
  int &r = dp2[left][t];
  if (r != -1) return r;
  return r = (f(left, t <= k) * 2LL % mod + 8LL * f2(left - 1, t + 1) % mod) %
             mod;
}
int get(string &str) {
  int aft = ctr(str);
  int n = str.size() - 1;
  int ans = 0;
  int last = -inf;
  aft = min(aft, n);
  for (int i = 0; i <= aft; i++) {
    int tt =
        (str[i] >= '7') + (str[i] >= '4') - (str[i] == '4') - (str[i] == '7');
    ans = (ans + f(n - i + 1, (i - last) <= k) * (long long)tt % mod) % mod;
    int t = str[i] - '0' - tt;
    ans =
        (ans + f2(n - i, min(i - last + 1, k + 1)) * (long long)t % mod) % mod;
    if (str[i] == '4' || str[i] == '7') last = i;
  }
  int t = 1;
  for (int i = n; i >= aft + 1; i--) {
    long long tt = str[i] - '0';
    ans = (ans + t * tt) % mod;
    t = (t * 10LL) % mod;
  }
  return ans;
}
int main() {
  scanf("%d %d", &t, &k);
  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  for (int i = 1; i <= t; i++) {
    scanf("%s", s);
    str = s;
    int ans = -get(str);
    scanf("%s", s);
    str = s;
    ans += (ctr(str) != inf) + get(str);
    ans = (ans % mod + mod) % mod;
    printf("%d\n", ans);
  }
  return 0;
}
