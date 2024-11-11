#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
char c1[111111], c2[111111];
int s[30], d[30];
int t;
int main(int argc, char *argv[]) {
  scanf("%s%s", c1, c2);
  if (strlen(c1) < strlen(c2)) {
    printf("0\n");
    return 0;
  }
  int l1 = strlen(c1), l2 = strlen(c2);
  for (int i = 0; i < l2; i++) {
    s[c1[i] - 'a']++;
    d[c2[i] - 'a']++;
  }
  int ans = 0;
  for (int i = 0; i <= l1 - l2; i++) {
    for (int j = 0; j < 26; j++) {
      if (s[j] > d[j]) {
        ans--;
        break;
      }
    }
    ans++;
    if (i < l1 - l2) {
      if (c1[i] != '?') {
        s[c1[i] - 'a']--;
      }
      if (c1[i + l2] != '?') {
        s[c1[i + l2] - 'a']++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
