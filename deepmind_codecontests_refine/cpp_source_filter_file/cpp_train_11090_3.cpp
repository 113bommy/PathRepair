#include <bits/stdc++.h>
const int N = 1e5 + 5;
char str[N];
char ans[N];
int s[N];
int n;
bool judge(void) {
  for (int i = 0; i < n / 2; ++i) {
    int l = i, r = n - 1 - i;
    if (s[l] == s[r])
      i++;
    else if (s[l] == s[r] + 1 || s[l] == s[r] + 11) {
      s[l]--;
      s[l + 1] += 10;
    } else if (s[l] == s[r] + 10) {
      s[r] += 10;
      s[r - 1]--;
    } else
      return false;
  }
  if (n % 2 == 1) {
    if (s[n / 2] % 2 == 1 || s[n / 2] > 18 || s[n / 2] < 0) return false;
    ans[n / 2] = s[n / 2] / 2 + '0';
  }
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] > 18 || s[i] < 0) return false;
    ans[i] = (s[i] + 1) / 2 + '0';
    ans[n - 1 - i] = s[i] / 2 + '0';
  }
  return ans[0] > '0';
}
int main(void) {
  scanf("%s", str);
  n = strlen(str);
  for (int i = 0; i < n; ++i) s[i] = str[i] - '0';
  if (judge())
    printf("%s\n", ans);
  else if (str[0] == '1' && n > 1) {
    for (int i = 0; i < n; ++i) {
      s[i] = str[i + 1] - '0';
    }
    s[0] += 10;
    n--;
    if (judge())
      printf("%s\n", ans);
    else
      puts("0");
  } else
    puts("0");
  return 0;
}
