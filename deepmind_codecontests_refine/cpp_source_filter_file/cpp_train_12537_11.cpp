#include <bits/stdc++.h>
int main() {
  int i, k, n, cnt;
  static int ii[3000];
  static char s[3002];
  scanf("%d", &n);
  scanf("%s", s);
  k = 0;
  for (i = 0; i < n; i++)
    if (s[i] != '.') ii[k++] = i;
  cnt = 0;
  for (i = 1; i < k; i++)
    if (s[ii[i - 1]] == 'L' && s[ii[i]] == 'R')
      cnt += ii[i] - ii[i - 1] - 1;
    else if (s[ii[i - 1]] == 'R' && s[ii[i]] == 'L' &&
             (ii[i - 1] + ii[i]) % 2 == 0)
      cnt++;
  if (s[ii[0]] == 'R') cnt += ii[0];
  if (s[ii[k - 1]] == 'L') cnt += n - ii[k - 1] - 1;
  printf("%d\n", k == 1 ? n : cnt);
  return 0;
}
