#include <bits/stdc++.h>
using namespace std;
char str[200005];
int z_array[200005];
void making_z_array(int len) {
  int L = 0, R = 0;
  for (int i = 1; i < len; i++) {
    if (i > R) {
      L = R = i;
      while (R < len && str[R - L] == str[R]) R++;
      z_array[i] = R - L;
      R--;
    } else {
      int k = i - L;
      if (z_array[k] < R - i + 1)
        z_array[i] = z_array[k];
      else {
        L = i;
        while (R < len && str[R - L] == str[R]) R++;
        z_array[i] = R - L;
        R--;
      }
    }
  }
}
char mainstr[100005];
char allstr[105][1005];
int fst[1005], lst[1005], n;
int func(char *s) {
  int len = strlen(s), i, j;
  if (len == 1) return 0;
  strcpy(str, s);
  strcat(str, mainstr);
  making_z_array(len + n);
  memset(fst, -1, sizeof(fst));
  for (i = len; i < len + n; i++) {
    int tmp = min(len, z_array[i]);
    if (tmp == len) return 1;
    for (j = tmp - 1; j >= 0; j--) {
      if (fst[j] != -1) break;
      fst[j] = i - len;
    }
  }
  for (i = 0; i < len; i++) str[i] = s[len - i - 1];
  for (i = 0; i < n; i++) str[len + i] = mainstr[n - i - 1];
  making_z_array(len + n);
  memset(lst, -1, sizeof(lst));
  for (i = len; i < n + len; i++) {
    int tmp = min(len, z_array[i]);
    for (j = tmp - 1; j >= 0; j--) {
      if (lst[j] != -1) break;
      lst[j] = n - (i - len) - 1;
    }
  }
  for (i = 0; i < len - 1; i++) {
    if (fst[i] == -1 || lst[len - i - 2] == -1) continue;
    if (lst[len - i - 2] - fst[i] + 1 >= len) return 1;
  }
  return 0;
}
int main() {
  scanf("%s", mainstr);
  n = strlen(mainstr);
  int i, m;
  scanf("%d", &m);
  for (i = 0; i < m; i++) scanf("%s", allstr[i]);
  int ans = 0;
  for (i = 0; i < m; i++) ans += func(allstr[i]);
  printf("%d\n", ans);
  return 0;
}
