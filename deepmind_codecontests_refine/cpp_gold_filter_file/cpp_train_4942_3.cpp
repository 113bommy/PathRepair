#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const long long mod = 1e9 + 7;
char S[maxn], T[maxn];
int slen, tlen;
int p[maxn];
long long dp[maxn], sum[maxn], sum2[maxn];
int Next[maxn];
void getNext() {
  int j, k;
  j = 0;
  k = -1;
  Next[0] = -1;
  while (j < tlen)
    if (k == -1 || T[j] == T[k])
      Next[++j] = ++k;
    else
      k = Next[k];
}
int KMP_Count() {
  int ans = 0;
  int i, j = 0;
  if (slen == 1 && tlen == 1) {
    if (S[0] == T[0]) {
      p[1] = 1;
      return 1;
    } else
      return 0;
  }
  getNext();
  for (i = 0; i < slen; i++) {
    while (j > 0 && S[i] != T[j]) j = Next[j];
    if (S[i] == T[j]) j++;
    if (j == tlen) {
      ans++;
      j = Next[j];
      p[i + 1] = 1;
    }
  }
  return ans;
}
int main() {
  gets(S);
  gets(T);
  slen = strlen(S), tlen = strlen(T);
  KMP_Count();
  for (int i = 1; i <= slen; i++) {
    if (!p[i])
      dp[i] = dp[i - 1];
    else
      dp[i] = sum[i - tlen] + i - tlen + 1;
    dp[i] %= mod;
    sum2[i] = sum2[i - 1] + dp[i];
    sum2[i] %= mod;
    sum[i] = sum[i - 1] + sum2[i];
    sum[i] %= mod;
  }
  printf("%lld\n", sum2[slen]);
  return 0;
}
