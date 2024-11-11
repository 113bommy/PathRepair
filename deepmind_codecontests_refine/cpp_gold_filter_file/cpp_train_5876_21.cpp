#include <bits/stdc++.h>
int main() {
  unsigned long long int i, j, k, a, b, n, k1, k2, count = 0, t, count1 = 0;
  char ch[1000], ch1[1000];
  scanf("%s %s", ch, ch1);
  n = strlen(ch);
  for (i = 0; i < n; i++) {
    if (ch[i] == ch1[n - 1 - i]) count++;
  }
  if (count == n)
    printf("YES");
  else
    printf("NO");
}
