#include <bits/stdc++.h>
int n;
int left[10];
char str[5][10] = {"S", "M", "L", "XL", "XXL"};
int map(char *s) {
  for (int i = 0; i < 5; i++)
    if (!strcmp(s, str[i])) return i;
  return -1;
}
char *map(int i) { return str[i]; }
int main() {
  for (int i = 0; i < 5; i++) scanf("%d", left + i);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    char s[100];
    scanf("%s", s);
    int tmp = map(s);
    int best = 0;
    for (int dist = 0; dist < 10; dist++) {
      if (tmp + dist < 5 && left[tmp + dist]) {
        left[tmp + dist]--;
        best = tmp + dist;
        break;
      }
      if (tmp - dist >= 0 && left[tmp - dist]) {
        left[tmp - dist]--;
        best = tmp - dist;
        break;
      }
    }
    printf("%s\n", map(best));
  }
  return 0;
}
