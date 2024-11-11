#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n, m, k;
char s[maxn];
int d[maxn * 2];
int sum[maxn * 2];
int pre[128];
int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  m = strlen(s + 1);
  sum[0] = 1;
  for (int i = 1; i <= m + n; i++) {
    char ch;
    if (i <= m)
      ch = s[i];
    else {
      ch = 'a';
      for (char i = 'a'; i < 'a' + k; i++)
        if (pre[i] < pre[ch]) ch = i;
    }
    if (pre[ch] == 0)
      d[i] = sum[i - 1];
    else
      d[i] = (sum[i - 1] - sum[pre[ch] - 1] + mod) % mod;
    sum[i] = sum[i - 1] + d[i];
    pre[ch] = i;
  }
  cout << sum[m + n] << endl;
  return 0;
}
