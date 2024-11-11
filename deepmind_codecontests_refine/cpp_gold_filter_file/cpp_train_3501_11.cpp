#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  int l[105], r[105], c1[105], c2[105];
  char str[105] = "";
  scanf("%d %d", &n, &m);
  scanf("%s", str);
  for (i = 0; i < m; i++) {
    scanf("%d %d %c %c", l + i, r + i, c1 + i, c2 + i);
  }
  for (i = 0; i < m; i++) {
    char ch = c1[i];
    char ch1 = c2[i];
    int left = l[i] - 1;
    int right = r[i];
    for (j = left; j < right; j++) {
      if (str[j] == ch) {
        str[j] = ch1;
      }
    }
  }
  printf("%s", str);
  return 0;
}
