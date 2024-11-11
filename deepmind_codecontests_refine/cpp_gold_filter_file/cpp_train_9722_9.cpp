#include <bits/stdc++.h>
const long long MOD = 1000000007;
long long p[200005];
char s1[100002], s2[100002];
bool isUn = false;
int sig = 0, len;
int cmp(int a, int b) {
  if (a > b) return 1;
  if (a < b) return -1;
  if (a == b) return 0;
}
int main() {
  p[0] = 1;
  for (int i = 1; i < 200005; i++) p[i] = p[i - 1] * 10 % MOD;
  scanf("%d", &len);
  scanf("%s%s", s1, s2);
  for (int i = 0; i < len; i++)
    if (s1[i] == '?' || s2[i] == '?')
      continue;
    else {
      int tmp = cmp(s1[i] - '0', s2[i] - '0');
      if (tmp * sig < 0) {
        isUn = true;
        break;
      }
      if (sig == 0) sig = tmp;
    }
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    if (s1[i] == '?') cnt++;
    if (s2[i] == '?') cnt++;
  }
  if (isUn)
    printf("%I64d\n", p[cnt]);
  else {
    long long ans = 1;
    if (sig > 0) {
      for (int i = 0; i < len; i++)
        if (s1[i] == '?' || s2[i] == '?') {
          if (s1[i] == '?' && s2[i] == '?')
            ans = ans * 55 % MOD;
          else if (s1[i] == '?')
            ans = ans * (10 - s2[i] + '0') % MOD;
          else
            ans = ans * (s1[i] - '0' + 1) % MOD;
        }
    } else if (sig < 0) {
      for (int i = 0; i < len; i++)
        if (s1[i] == '?' || s2[i] == '?') {
          if (s1[i] == '?' && s2[i] == '?')
            ans = ans * 55 % MOD;
          else if (s1[i] == '?')
            ans = ans * (s2[i] - '0' + 1) % MOD;
          else
            ans = ans * (10 - s1[i] + '0') % MOD;
        }
    } else {
      long long ans1 = 1, ans2 = 1;
      for (int i = 0; i < len; i++)
        if (s1[i] == '?' || s2[i] == '?') {
          if (s1[i] == '?' && s2[i] == '?')
            ans1 = ans1 * 55 % MOD;
          else if (s1[i] == '?')
            ans1 = ans1 * (s2[i] - '0' + 1) % MOD;
          else
            ans1 = ans1 * (10 - s1[i] + '0') % MOD;
        }
      for (int i = 0; i < len; i++)
        if (s1[i] == '?' || s2[i] == '?') {
          if (s1[i] == '?' && s2[i] == '?')
            ans2 = ans2 * 55 % MOD;
          else if (s1[i] == '?')
            ans2 = ans2 * (10 - s2[i] + '0') % MOD;
          else
            ans2 = ans2 * (s1[i] - '0' + 1) % MOD;
        }
      ans = ans1 + ans2;
      long long tmp = 1;
      for (int i = 0; i < len; i++)
        if (s1[i] == '?' || s2[i] == '?') {
          if (s1[i] == '?' && s2[i] == '?') tmp = tmp * 10;
        }
      ans = ((ans - tmp) % MOD + MOD) % MOD;
    }
    ans = ((p[cnt] - ans) % MOD + MOD) % MOD;
    printf("%I64d\n", ans);
  }
  return 0;
}
