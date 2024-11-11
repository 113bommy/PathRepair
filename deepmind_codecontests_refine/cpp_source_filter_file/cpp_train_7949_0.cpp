#include <bits/stdc++.h>
using namespace std;
long long cnt[11];
int sz;
string num;
void dp(int nw, long long cn, int len, bool reached) {
  if (sz == len) {
    cnt[nw] += cn;
    return;
  }
  if (!reached) {
    dp(nw + 1, cn * 2, len + 1, 0);
    dp(nw, cn * 8, len + 1, 0);
    return;
  } else if (num[len] < '4') {
    dp(nw, cn, len + 1, 1);
    dp(nw, cn * (num[len] - '0'), len + 1, 0);
  } else if (num[len] == '4') {
    dp(nw + 1, cn, len + 1, 1);
    dp(nw, cn * 4, len + 1, 0);
  } else if (num[len] > '4' && num[len] < '7') {
    dp(nw + 1, cn, len + 1, 0);
    dp(nw, cn, len + 1, 1);
    dp(nw, cn * (num[len] - '0' - 1), len + 1, 1);
  } else if (num[len] == '7') {
    dp(nw + 1, cn, len + 1, 1);
    dp(nw + 1, cn, len + 1, 0);
    dp(nw, cn * 6, len + 1, 0);
  } else {
    dp(nw + 1, cn * 2, len + 1, 0);
    dp(nw, cn, len + 1, 1);
    dp(nw, cn * (num[len] - '0' - 2), len + 1, 0);
  }
}
constexpr int MOD = 1000000007;
long long fall(long long n) {
  long long res = 1;
  for (int i = 0; i < 6; i++) {
    res *= n;
    res %= MOD;
    n--;
  }
  return res;
}
long long solve(int mx, int cn) {
  if (cn == 0) return 1;
  long long res = 0;
  for (int i = 0; i <= mx; i++) {
    if (cnt[i] == 0) continue;
    cnt[i]--;
    res += (cnt[i] + 1) * solve(mx - i, cn - 1) % MOD;
    res %= MOD;
    cnt[i]++;
  }
  return res;
}
int main() {
  cin >> num;
  sz = num.size();
  dp(0, 1, 0, 1);
  cnt[0]--;
  long long res = 0;
  long long aa = 0;
  for (int i = 1; i <= 10; i++) {
    res += cnt[i] * solve(i - 1, 6) % MOD;
    res %= MOD;
  }
  cout << res;
  return 0;
}
