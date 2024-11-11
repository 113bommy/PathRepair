#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2000200, p = 1e9 + 7;
int n, k;
char s[Maxn];
int sum[Maxn];
int dp[Maxn];
int tp[26], cnt[26];
int pre[33];
void up(int &x, int y) {
  x += y;
  if (x >= p) x -= p;
}
int main() {
  cin >> n >> k;
  scanf("%s", s + 1);
  int ls = strlen(s + 1);
  sum[0] = 1;
  for (int i = 1; i <= ls; i++) {
    int c = s[i] - 'a';
    dp[i] = sum[i - 1];
    sum[i] = (0LL + sum[i - 1] + dp[i] - tp[c] + p) % p;
    tp[c] = dp[i];
    cnt[c]++;
    pre[c] = i;
  }
  for (int i = ls + 1; i <= ls + n; i++) {
    int c = 0;
    for (int j = 1; j < k; j++)
      if (cnt[j] < cnt[c]) c = j;
    dp[i] = sum[i - 1];
    sum[i] = (0LL + sum[i - 1] + dp[i] - tp[c] + p) % p;
    tp[c] = dp[i];
    cnt[c]++;
    pre[c] = i;
  }
  printf("%d\n", sum[ls + n]);
}
