#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007;
const int MAXN = 1000005;
int n, k;
char s[MAXN];
long long ans;
void inc(long long &a, long long b) { a = (a + b) % P; }
void dec(long long &a, long long b) { inc(a, P - b); }
long long mul(long long a, long long b) { return a * b % P; }
long long *calc(const char *s, char base) {
  long long *buf = new long long[n * 2];
  long long *ans = new long long[n];
  fill(buf, buf + n * 2, 0LL);
  long long *dp = buf + n;
  dp[0] = 1;
  int filled = 1;
  long long sum = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'X') {
      dp[-1] = sum;
      sum = mul(sum, 2);
    } else if (s[i] != base) {
      dp[-1] = sum;
      fill(dp, dp + filled, 0LL);
      filled = 0;
    }
    filled++;
    dp--;
    ans[i] = dp[k];
    dec(sum, dp[k]);
  }
  return ans;
}
int main() {
  scanf("%d%d\n", &n, &k);
  gets(s);
  long long *q_b = calc(s, 'B');
  reverse(s, s + n);
  long long *q_w = calc(s, 'W');
  reverse(s, s + n);
  reverse(q_w, q_w + n);
  long long all = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    inc(ans, mul(sum, q_w[i]));
    if (s[i] == 'X') sum = mul(sum, 2);
    inc(sum, q_b[i]);
  }
  cout << ans;
  return 0;
}
