#include <bits/stdc++.h>
using namespace std;
long long Next[100007], mark[100007] = {}, dp[100007] = {1}, f[100007],
                        sum[100007] = {1};
char s[100007], t[100007];
void getNext() {
  int l = strlen(t + 1);
  Next[1] = 0;
  for (int i = 1, j = 0; i <= l;)
    if (j == 0 || t[i] == t[j])
      Next[++i] = ++j;
    else
      j = Next[j];
}
void kmp() {
  int l = strlen(s + 1), tl = strlen(t + 1);
  for (int i = 1, j = 1; i <= l;) {
    if (j == 0 || s[i] == t[j]) {
      i++, j++;
      if (j == tl + 1) mark[i - 1] = 1;
    } else
      j = Next[j];
  }
  int cur = -1;
  for (int i = 1; i <= l; i++) {
    if (mark[i]) cur = i - tl;
    f[i] = cur;
  }
}
int solve() {
  int l = strlen(s + 1);
  for (int i = 1; i <= l; i++) {
    if (f[i] == -1)
      dp[i] = 1;
    else
      dp[i] = (dp[i - 1] + sum[f[i]]) % 1000000007;
    sum[i] = (sum[i - 1] + dp[i]) % 1000000007;
  }
  return (dp[l] + 1000000007 - 1) % 1000000007;
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  getNext(), kmp();
  cout << solve() << endl;
  return 0;
}
