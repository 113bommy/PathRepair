#include <bits/stdc++.h>
int ctoi(char c);
int main() {
  int n = 0, i, j;
  char s[100001], p[100001];
  int len_s, len_p;
  int table_p[26] = {0}, table_s[27];
  scanf("%s", s);
  scanf("%s", p);
  len_s = strlen(s);
  len_p = strlen(p);
  if (len_s < len_p) {
    printf("0\n");
    return 0;
  }
  for (i = 0; i < len_p; i++) {
    table_s[ctoi(s[i])]++;
    table_p[ctoi(p[i])]++;
  }
  for (i = 0; i < len_s - len_p + 1; i++) {
    int diff = 0;
    for (j = 0; j < 26; j++) {
      int d = table_p[j] - table_s[j];
      if (0 <= d) {
        diff += d;
      } else
        break;
    }
    if (26 <= j && table_s[26] == diff) n++;
    table_s[ctoi(s[i])]--;
    table_s[ctoi(s[i + len_p])]++;
  }
  printf("%d\n", n);
  return 0;
}
int ctoi(char c) {
  if (c == '?' || c == '\0')
    return 26;
  else
    return c - 'a';
}
