#include <bits/stdc++.h>
int n;
char wor[100010];
int sen[100010];
int chk(int st, int len, char c1[], char c2[]) {
  for (int i = st, j = 0; j < len; ++i, ++j)
    if (c1[i] != c2[j]) return 0;
  return 1;
}
int type(char str[]) {
  int si = 0;
  while (str[si] != '\0') ++si;
  if (si >= 4 && chk(si - 4, 4, str, "lios")) return 0;
  if (si >= 5 && chk(si - 5, 5, str, "liala")) return 1;
  if (si >= 3 && chk(si - 3, 3, str, "etr")) return 2;
  if (si >= 4 && chk(si - 4, 4, str, "etra")) return 3;
  if (si >= 6 && chk(si - 6, 6, str, "initis")) return 4;
  if (si >= 6 && chk(si - 6, 6, str, "inites")) return 5;
  return -1;
}
int main(void) {
  while (scanf("%s", wor) != EOF) {
    int t = type(wor);
    sen[n++] = t;
  }
  for (int i = 0; i < n; ++i) {
    if (sen[i] < 0) {
      puts("NO");
      return 0;
    }
  }
  if (n == 1) {
    puts("YES");
    return 0;
  }
  int ok = 1;
  for (int i = 1; i < n; ++i) {
    if ((sen[i] & 1) != (sen[i - 1] & 1)) {
      puts("NO");
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) sen[i] &= (~1);
  int cnt[10];
  cnt[0] = cnt[2] = cnt[4] = 0;
  for (int i = 0; i < n; ++i) ++cnt[sen[i]];
  if (cnt[2] != 1) {
    puts("NO");
    return 0;
  }
  int p = 0;
  for (; p < n; ++p) {
    if (sen[p] == 2) break;
    if (sen[p] == 4) {
      puts("NO");
      return 0;
    }
  }
  for (++p; p < n; ++p) {
    if (sen[p] == 0) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
