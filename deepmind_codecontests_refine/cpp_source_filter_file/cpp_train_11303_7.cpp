#include <bits/stdc++.h>
using namespace std;
long long n, d;
string s;
long long pown[65] = {0};
long long MAXN = (1e18) * 1LL;
long long INF = LLONG_MAX / 5;
bool mul(long long a, long long b) { return ((MAXN / max(a, b)) >= min(a, b)); }
bool add(long long a, long long b) { return (MAXN - b >= a); }
long long dp[65][65];
long long rec(long long ptr, long long lvl) {
  if (ptr >= s.size()) {
    return 0;
  } else if (pown[lvl] == 0) {
    return INF;
  }
  if (dp[ptr][lvl] != -1) {
    return dp[ptr][lvl];
  }
  long long ans = INF, val = 0, ten = 1;
  for (long long i = (long long)(ptr);
       i <= (long long)(min(ptr + d - 1, (long long)s.size() - 1)); i++) {
    val += (s[i] - '0') * ten;
    ten *= 10;
    if (val >= n || !mul(val, pown[lvl])) break;
    if (val == 0 && i > ptr) continue;
    long long a = (pown[lvl] * val);
    long long b = rec(i + 1, lvl + 1);
    if (add(a, b)) {
      ans = min(ans, a + b);
    }
  }
  return dp[ptr][lvl] = ans;
}
int main() {
  cin >> n >> s;
  long long val = n;
  while (val > 0) {
    val /= 10;
    d++;
  }
  reverse((s).begin(), (s).end());
  pown[0] = 1;
  for (long long i = (long long)(1); i <= (long long)(60); i++) {
    if (!mul(pown[i - 1], n)) break;
    pown[i] = (pown[i - 1] * n);
  }
  memset(dp, -1, sizeof dp);
  cout << rec(0, 0);
}
