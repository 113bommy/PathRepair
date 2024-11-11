#include <bits/stdc++.h>
int k;
int vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int rhyme(char *s, char *t) {
  int n, m, i, j, cnt;
  n = strlen(s);
  m = strlen(s);
  for (i = n - 1, cnt = 0; i >= 0 && cnt < k; i--)
    if (vowel(s[i])) cnt++;
  if (cnt < k) return 0;
  for (j = m - 1, cnt = 0; j >= 0 && cnt < k; j--)
    if (vowel(t[j])) cnt++;
  if (cnt < k) return 0;
  i++, j++;
  return strcmp(s + i, t + j) == 0;
}
int aaaa[] = {1, 2, 3, 0};
int aabb[] = {1, 0, 3, 2};
int abab[] = {2, 3, 0, 1};
int abba[] = {3, 2, 1, 0};
char ans[][8] = {"aaaa", "aabb", "abab", "abba", "NO"};
int check(int *aa, char ss[][10000 + 1]) {
  int i;
  for (i = 0; i < 4; i++)
    if (!rhyme(ss[i], ss[aa[i]])) return 0;
  return 1;
}
int main() {
  static char ss[4][10000 + 1];
  int n, i, j, idx;
  scanf("%d%d", &n, &k);
  idx = -1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 4; j++) scanf("%s", ss[j]);
    if (check(aaaa, ss)) {
      if (idx == -1) idx = 0;
    } else if (check(aabb, ss)) {
      if (idx != -1 && idx != 1 && idx != 0) {
        idx = 4;
        break;
      }
      idx = 1;
    } else if (check(abab, ss)) {
      if (idx != -1 && idx != 2 && idx != 0) {
        idx = 4;
        break;
      }
      idx = 2;
    } else if (check(abba, ss)) {
      if (idx != -1 && idx != 3 && idx != 0) {
        idx = 4;
        break;
      }
      idx = 3;
    } else {
      idx = 4;
      break;
    }
  }
  printf("%s\n", ans[idx]);
  return 0;
}
