#include <bits/stdc++.h>
int n, m;
char s[100001];
int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  long long c = 0;
  for (int i = 0; s[i] != '\0';) {
    int j = i;
    while (s[j] == s[i]) ++j;
    c += n * (m - 1);
    i = j;
  }
  for (int i = 0; s[i] != '\0';) {
    int j = i + 1;
    if (s[j] == '\0') break;
    if (s[j] == s[i]) {
      i = j;
    } else {
      int k = j + 1;
      while (s[k] == s[k - 2]) ++k;
      c -= static_cast<long long>(k - i) * (k - i - 1) / 2;
      i = k - 1;
    }
  }
  printf("%It4d\n", c);
}
