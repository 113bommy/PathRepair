#include <bits/stdc++.h>
using namespace std;
char str[1000010], s[3 * 1000010];
int R[3 * 1000010], L[1000010];
int dp[3 * 1000010];
int len;
int olen;
int f(int end, int cur);
int main() {
  while (scanf("%s", str) == 1) {
    s[0] = 0;
    len = strlen(str);
    strcat(s, str);
    strcat(s, str);
    strcat(s, str);
    bool all0, all1;
    int end = -1;
    all0 = all1 = true;
    int start = -1;
    memset(dp, -1, sizeof(dp));
    memset(R, -1, sizeof(R));
    for (int i = 0; i < len; i++) {
      if ((s[i] == '0' && s[(i - 1 + len) % len] == '1') ||
          (s[i] == '1' && s[(i - 1 + len) % len] == '0'))
        start = i;
      if (s[i] == '0') {
        all1 = false;
      } else {
        all0 = false;
      }
    }
    if (all0 || all1) {
      puts("1");
      continue;
    }
    for (int i = 0; i < 2 * len; i++) {
      int t = i;
      char ch = s[i];
      if (R[i] != -1) continue;
      while (t < 3 * len && s[t] == ch) {
        t++;
      }
      for (int j = i; j < t; j++) R[j] = t + 1;
    }
    int j = start + len - 1;
    char ch = s[j];
    do {
      if (ch != s[j]) {
        end = j;
        break;
      }
      j = j - 1;
    } while (j != start);
    end++;
    int sol1 = 1 + f(end, R[start]);
    memset(dp, -1, sizeof(dp));
    int sol2 = f(start + len, start + 1);
    printf("%d\n", max(sol1, sol2));
  }
  return 0;
}
int f(int end, int cur) {
  if (cur >= end) return 0;
  int ret = 0;
  if (dp[cur] != -1) return dp[cur];
  ret = max(1 + f(end, R[cur]), f(end, cur + 1));
  return dp[cur] = ret;
}
