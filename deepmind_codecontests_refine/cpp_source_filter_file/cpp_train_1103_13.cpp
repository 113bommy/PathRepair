#include <bits/stdc++.h>
using namespace std;
int a[15];
char s[200005];
int main() {
  int k;
  scanf("%d", &k);
  scanf("%s", s);
  for (int i = 0; i < strlen(s); i++) {
    a[s[i] - '0']++;
    k -= s[i] - '0';
  }
  int ans = 0;
  if (k < 0) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < 9; i++)
    while (a[i]) {
      a[i]--;
      k -= 9 - i;
      ans++;
      if (k <= 0) {
        printf("%d\n", ans);
        return 0;
      }
    }
  return 0;
}
