#include <bits/stdc++.h>
char s[1000000];
int ans[30];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  int f = 0;
  int len = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == s[i - 1])
      len++;
    else
      len = 1;
    if (len >= k) {
      len -= k;
      ans[s[i] - 'a']++;
    }
  }
  int max = 0;
  for (int i = 1; i <= 26; i++) max = std::max(max, ans[i - 1]);
  printf("%d\n", max);
}
