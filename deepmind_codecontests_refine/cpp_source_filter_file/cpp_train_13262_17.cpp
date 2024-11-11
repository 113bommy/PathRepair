#include <bits/stdc++.h>
using namespace std;
char s1[1000], s2[1000];
int num[100], tot[100];
int main() {
  scanf("%s", s1);
  for (int i = 0; s1[i]; i++) {
    if (s1[i] == '6' || s1[i] == '9') {
      num[6]++;
    } else if (s1[i] == '2' || s1[i] == '5') {
      num[5]++;
    } else {
      num[s1[i] - '0']++;
    }
  }
  scanf("%s", s2);
  for (int i = 0; s2[i]; i++) {
    if (s2[i] == '6' || s2[i] == '9') {
      tot[6]++;
    } else if (s2[i] == '2' || s2[i] == '5') {
      tot[2]++;
    } else {
      tot[s2[i] - '0']++;
    }
  }
  int ans = 100000;
  for (int i = 0; i <= 9; i++) {
    if (i == 9 || i == 5) continue;
    if (!num[i]) continue;
    ans = min(ans, tot[i] / num[i]);
  }
  printf("%d\n", ans);
  return 0;
}
