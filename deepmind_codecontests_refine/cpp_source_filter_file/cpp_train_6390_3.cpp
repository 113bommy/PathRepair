#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int mod = 1e9 + 7;
long long ans[N], sum[N], sum1[N], sum2[N], val[N], val2[N], tmp[N];
long long work(char ch[N]) {
  int n = strlen(ch);
  sum[0] = 1;
  for (int i = 1; i <= n; i++) {
    int x = ch[i - 1] - '0';
    ans[i] = (100 * sum2[i - 1] + 110 * sum1[i - 1] + 28 * sum[i - 1]) % mod;
    ans[i] = (ans[i] + 100 * ans[i - 1] + 110 * sum1[i - 1] +
              28 * (sum[i - 1] - 1 + mod)) %
             mod;
    ans[i] = (ans[i] - (40 * val[i - 1] + 70 * tmp[i - 1]) % mod + mod) % mod;
    long long flag = 0;
    val[i] = (val[i - 1] * 10 + x) % mod;
    val2[i] = val[i] * val[i] % mod;
    sum[i] = (2 * sum[i - 1]) % mod;
    sum1[i] = 20 * sum1[i - 1] + 11 * sum[i - 1] % mod;
    sum2[i] = (200 * sum2[i - 1] + 220 * sum1[i - 1] + 65 * sum[i - 1]) % mod;
    tmp[i] = (tmp[i - 1] * 10 + 4) % mod;
    if (x == 4) {
      sum[i] = (sum[i] - 1 + mod) % mod;
      sum1[i] = (sum1[i] - (val[i - 1] * 10 + 7) % mod + mod) % mod;
      sum2[i] =
          (sum2[i] - (val2[i - 1] * 100 + val[i - 1] * 140 + 49) % mod + mod) %
          mod;
      flag = (100 * val2[i - 1] + 110 * val[i - 1] + 28) % mod;
    }
    ans[i] = (ans[i] - flag + mod) % mod;
  }
  return ans[n];
}
char cha[N], chb[N];
int main() {
  cin >> cha >> chb;
  long long ans = (work(chb) - work(cha) + mod) % mod;
  cout << ans << endl;
}
