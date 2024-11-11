#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int NN = 1000005;
int n, k, len, pos[NN], c;
long long sum[NN], ans = 1ll;
char ch[NN];
int main() {
  scanf("%d%d%s", &n, &k, ch);
  len = strlen(ch);
  for (int i = 0; i < len; ++i) {
    long long pre = ans;
    ans = ((ans * 2 - sum[c = ch[i] - 'a']) % mod + mod) % mod;
    pos[c] = i + 1, sum[c] = pre;
  }
  for (int i = 0; i < n; ++i) {
    int mx = NN, p = 0;
    for (int j = 0; j < k; ++j)
      if (pos[j] < mx) mx = pos[j], p = j;
    long long pre = ans;
    ans = ((ans * 2 - sum[p]) % mod + mod) % mod;
    sum[p] = pre, pos[p] = i + len + 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
