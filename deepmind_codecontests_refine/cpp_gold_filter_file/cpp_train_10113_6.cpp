#include <bits/stdc++.h>
using namespace std;
int n, a, b;
bool flag;
char s[5010];
int nxt[5010];
int pos[5010];
int dp[5010];
void get_nxt(int p) {
  int k = 0;
  nxt[p] = 0;
  for (int i = p + 1; i < n; i++) {
    while (k > 0 && s[i] != s[p + k]) k = nxt[p + k - 1];
    if (s[i] == s[p + k]) k++;
    nxt[i] = k;
  }
  for (int i = p + 1; i < n; i++) {
    k = nxt[i];
    while (k * 2 > i - p + 1 && k > 0) k = nxt[p + k - 1];
    pos[i + 1] = min(pos[i + 1], i - k + 1);
  }
}
void init() {
  cin >> n >> a >> b;
  memset(pos, 0x3f3f3f3f, sizeof(pos));
  pos[1] = 1;
  scanf("%s", s);
  for (int i = 1; i < n; i++)
    if (s[i] != s[i - 1]) flag = 1;
  if (flag) {
    for (int i = 0; i < n - 1; i++) get_nxt(i);
  } else {
    for (int i = 2; i <= n; i++) pos[i] = (i + 1) / 2;
  }
}
void cal() {
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[1] = a;
  for (int i = 2; i <= n; i++) dp[i] = min(dp[i - 1] + a, dp[pos[i]] + b);
  cout << dp[n];
}
int main() {
  init();
  cal();
  cin.get();
  cin.get();
  return 0;
}
