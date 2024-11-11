#include <bits/stdc++.h>
using namespace std;
char s[10010], str[30030];
int main() {
  int n, r[350], l[350], k[350];
  cin >> s;
  int len = strlen(s);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &l[i], &r[i], &k[i]);
    l[i]--;
    r[i]--;
    k[i] = k[i] % (r[i] - l[i] + 1);
    for (int j = l[i]; j <= r[i]; j++) {
      if (r[i] - j >= k[i]) {
        str[j + k[i]] = s[j];
      } else {
        str[l[i] + j + k[i] - r[i] - 1] = s[j];
      }
    }
    for (int j = l[i]; j <= r[i]; j++) {
      s[j] = str[j];
    }
  }
  for (int i = 0; i < len; i++) {
    printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}
