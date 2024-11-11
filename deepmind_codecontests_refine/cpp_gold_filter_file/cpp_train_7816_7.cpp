#include <bits/stdc++.h>
int main() {
  long long int n, t, i, j, count = 0;
  scanf("%lld", &n);
  char s[100005];
  char c[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  if (n == 1) {
    printf("YES\n");
    return 0;
  }
  for (i = 0; i <= n; i++) {
    scanf("%c", &s[i]);
  }
  for (j = 0; j < 26; j++) {
    count = 0;
    for (i = 0; i <= n; i++) {
      if (c[j] == s[i]) {
        count++;
        if (count >= 2) {
          printf("YES\n");
          return 0;
        }
      }
    }
  }
  printf("NO");
}
