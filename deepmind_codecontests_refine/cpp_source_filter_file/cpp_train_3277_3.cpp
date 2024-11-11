#include <bits/stdc++.h>
int main() {
  int n, st[100004] = {0}, k;
  long int i, j, ans = 0, l;
  char s[100004], c;
  scanf("%s", s);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    st[j]++;
  }
  l = strlen(s);
  if (l % 2 == 0)
    j = l / 2;
  else
    j = (l / 2) + 1;
  ans = st[1];
  for (i = 1; i <= j; i++) {
    if (ans % 2) {
      c = s[i - 1];
      s[i - 1] = s[l - i];
      s[l - i] = c;
    }
    ans += st[i + 1];
  }
  printf("%s", s);
  return 0;
}
