#include <bits/stdc++.h>
using namespace std;
int len, ans;
char s[1000005];
int gao(int i, int len1, int k, int len2) {
  if (len1 != len2) return len1 - len2;
  for (int j = 0; j < len1; j++) {
    if (s[i] != s[k]) return s[i] - s[j];
    i++;
    k++;
  }
  return 0;
}
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = len - 1; i >= 0; i--) {
    int k = i;
    while (k >= 0 && s[k] == '0') k--;
    ans++;
    if (k == 0) break;
    if (gao(0, k, k, i - k + 1) < 0) break;
    i = k;
  }
  printf("%d\n", ans);
  return 0;
}
