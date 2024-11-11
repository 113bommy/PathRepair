#include <bits/stdc++.h>
char s[50005];
int pd = 1, f[2605][2605];
void Print(int l, int r) {
  if (l > r)
    return;
  else if (l == r) {
    if (pd) printf("%c", s[l]);
  } else if (s[l] == s[r]) {
    printf("%c", s[l]);
    Print(l + 1, r - 1);
    printf("%c", s[r]);
  } else {
    if (f[l][r - 1] > f[l + 1][r])
      Print(l, r - 1);
    else
      Print(l + 1, r);
  }
}
int main() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  if (len > 2600) {
    int count[32] = {0};
    for (int i = 1; i <= len; ++i) {
      ++count[s[i] - 'A'];
      if (count[s[i] - 'A'] >= 100) {
        for (int j = 1; j <= 100; ++j) printf("%c", s[i]);
        return 0;
      }
    }
  }
  for (int i = len; i; --i) {
    f[i][i] = 1;
    for (int j = i + 1; j <= len; ++j) {
      if (s[i] == s[j]) {
        f[i][j] = f[i + 1][j - 1] + 2;
      } else {
        f[i][j] = std::max(f[i + 1][j], f[i][j - 1]);
      }
      if (f[i][j] >= 100) {
        pd = 0;
        Print(i, j);
        return 0;
      }
    }
  }
  Print(1, len);
  return 0;
}
