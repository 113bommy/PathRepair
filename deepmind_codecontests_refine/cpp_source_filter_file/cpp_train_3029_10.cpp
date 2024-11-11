#include <bits/stdc++.h>
const int inf = 1 << 30;
char s[200010], t[200010], s2[200010], t2[200010];
int pos_s[200010], pos_t[200010], len_s, len_t;
int pos_s2[200010], pos_t2[200010], len_s2, len_t2;
int min(int a, int b) { return a < b ? a : b; }
void remake(int fr_i, int fr_j, char* s = ::s, char* t = ::t, char* s2 = ::s2,
            char* t2 = ::t2, int* pos_s2 = ::pos_s2, int* pos_t2 = ::pos_t2,
            int& len_s2 = ::len_s2, int& len_t2 = ::len_t2) {
  int ls = 0, lt = 0;
  for (int k = 0; k < pos_s[fr_i]; k++) t2[lt++] = s[k];
  for (int k = 0; k < pos_t[fr_j]; k++) s2[ls++] = t[k];
  for (int k = pos_s[fr_i]; s[k]; k++) s2[ls++] = s[k];
  for (int k = pos_t[fr_j]; t[k]; k++) t2[lt++] = t[k];
  s2[ls] = t2[lt] = 0;
  len_s2 = len_t2 = 0;
  for (int i = 0, j = 0; s2[i]; i = j) {
    for (; s2[j] == s2[i]; j++)
      ;
    pos_s2[++len_s2] = j;
  }
  for (int i = 0, j = 0; t2[i]; i = j) {
    for (; t2[j] == t2[i]; j++)
      ;
    pos_t2[++len_t2] = j;
  }
}
int solve(char* s, char* t, int* pos_s, int* pos_t, int len_s, int len_t,
          int& fr_i, int& fr_j, bool ty) {
  int ans = s[0] != t[0] ? len_s > len_t ? len_s - 1 : len_t - 1 : inf, tmp;
  fr_i = -1;
  for (int i = 0; i <= len_s; i++) {
    for (int j = 0; j <= (i < 2 ? len_t : 1); j++) {
      int cs = len_s - i + j - 1, ct = len_t - j + i - 1,
          s0 = j ? t[0] : s[pos_s[i]], t0 = i ? s[0] : t[pos_t[j]];
      if (i && j < len_t && s[pos_s[i - 1]] == t[pos_t[j]]) ct--;
      if (j && i < len_s && t[pos_t[j - 1]] == s[pos_s[i]]) cs--;
      int tmp;
      if ((i + j == 1 || i + j == 3) && ty) {
        remake(i, j);
        int fr_i2 = -1, fr_j2;
        tmp =
            1 + solve(s2, t2, pos_s2, pos_t2, len_s2, len_t2, fr_i2, fr_j2, 0);
        if (tmp < ans) ans = tmp, fr_i = i, fr_j = j;
      } else if (s0 == 'a' && t0 == 'b' || s0 == 'b' && t0 == 'a') {
        tmp = 1 + (cs > ct ? cs : ct);
        if (tmp < ans) ans = tmp, fr_i = i, fr_j = j;
      }
    }
  }
  return ans;
}
int main() {
  scanf("%s%s", s, t);
  for (int i = 0, j = 0; s[i]; i = j) {
    for (; s[j] == s[i]; j++)
      ;
    pos_s[++len_s] = j;
  }
  for (int i = 0, j = 0; t[i]; i = j) {
    for (; t[j] == t[i]; j++)
      ;
    pos_t[++len_t] = j;
  }
  int ans, fr_i, fr_j;
  ans = solve(s, t, pos_s, pos_t, len_s, len_t, fr_i, fr_j, 1);
  printf("%d\n", ans);
  if (fr_i + fr_j == 1 || fr_i + fr_j == 3) {
    printf("%d %d\n", pos_s[fr_i], pos_t[fr_j]);
    remake(fr_i, fr_j);
    remake(0, 0, s2, t2, s, t, pos_s, pos_t, len_s, len_t);
    ans = solve(s, t, pos_s, pos_t, len_s, len_t, fr_i, fr_j, 1);
  }
  if (fr_i != -1)
    printf("%d %d\n", pos_s[fr_i], pos_t[fr_j]), --ans;
  else
    fr_i = fr_j = 0;
  remake(fr_i, fr_j);
  int left_s = 0, left_t = 0;
  for (int i = 1; i <= ans; i++) {
    int x = pos_s2[min(i, len_s2)] - left_s,
        y = pos_t2[min(i, len_t2)] - left_t;
    printf("%d %d\n", x, y);
    left_s += x - y;
    left_t += y - x;
  }
}
