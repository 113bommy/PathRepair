#include <bits/stdc++.h>
using namespace std;
char s[5010];
int far1[5010], far2[5010];
int main() {
  scanf("%s", s);
  int n = (int)strlen(s);
  for (int i = 0; i < n; i++) {
    int cnt = 0, j;
    for (j = i; j < n; j++) {
      if (s[j] == ')')
        cnt--;
      else
        cnt++;
      if (cnt < 0) break;
    }
    far1[i] = j;
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0, j;
    for (j = i; j >= 0; j--) {
      if (s[j] == '(')
        cnt--;
      else
        cnt++;
      if (cnt < 0) break;
    }
    far2[i] = j;
  }
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j += 2)
      if (far1[i] > j && far2[j] < i) res++;
  printf("%d", res);
  return 0;
}
