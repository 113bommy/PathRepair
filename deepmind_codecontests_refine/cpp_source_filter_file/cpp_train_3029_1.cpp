#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
char s[N], t[N];
vector<int> S, T;
int n, m, xx, yy;
int calc(int n, int m, char x, char y) {
  if (n && m && x == y) n < m ? n++ : m++;
  return max(n, m) - 1;
}
int main() {
  scanf("%s%s", s, t);
  int ls = strlen(s);
  int lt = strlen(t);
  s[ls] = '#', t[lt] = '#';
  for (int i = (int)(0); i <= (int)(ls - 1); i++)
    n += (i == 0 || s[i] != s[i - 1]);
  for (int i = (int)(0); i <= (int)(lt - 1); i++)
    m += (i == 0 || t[i] != t[i - 1]);
  int ans = calc(n, m, s[0], t[0]);
  for (int i = 0, n2 = 0; i <= ls; i++)
    if (!i || s[i] != s[i - 1]) {
      for (int j = 0, m2 = 0; j <= lt; j++)
        if (!j || t[j] != t[j - 1]) {
          int n3 = n - n2 + m2 - (j && t[j - 1] == s[i]);
          int m3 = m + n2 - m2 - (i && s[i - 1] == t[j]);
          char x3 = (j ? t[0] : s[i]), y3 = (i ? s[0] : t[j]);
          int tmp = 1 + calc(n3, m3, x3, y3);
          if (tmp < ans) ans = tmp, xx = i, yy = j;
          m2++;
        }
      if (n2++ == 3) break;
    }
  for (int j = 0, m2 = 0; j <= lt; j++)
    if (!j || t[j] != t[j - 1]) {
      for (int i = 0, n2 = 0; i <= ls; i++)
        if (!i || s[i] != s[i - 1]) {
          int n3 = n - n2 + m2 - (j && t[j - 1] == s[i]);
          int m3 = m + n2 - m2 - (i && s[i - 1] == t[j]);
          char x3 = (j ? t[0] : s[i]), y3 = (i ? s[0] : t[j]);
          int tmp = 1 + calc(n3, m3, x3, y3);
          if (tmp < ans) ans = tmp, xx = i, yy = j;
          n2++;
        }
      if (m2++ == 3) break;
    }
  printf("%d\n", ans);
  if (xx || yy) {
    static char ss[N], tt[N];
    memcpy(ss, s, sizeof(ss));
    ;
    memcpy(tt, t, sizeof(tt));
    ;
    int LS = ls, LT = lt;
    ls = lt = 0;
    for (int i = (int)(0); i <= (int)(yy - 1); i++) s[ls++] = tt[i];
    for (int i = (int)(xx); i <= (int)(LS - 1); i++) s[ls++] = ss[i];
    for (int i = (int)(0); i <= (int)(xx - 1); i++) t[lt++] = ss[i];
    for (int i = (int)(yy); i <= (int)(LT - 1); i++) t[lt++] = tt[i];
    printf("%d %d\n", xx, yy);
  }
  for (int i = (int)(1); i <= (int)(ls - 1); i++)
    if (s[i] != s[i - 1]) S.push_back(i);
  for (int i = (int)(1); i <= (int)(lt - 1); i++)
    if (t[i] != t[i - 1]) T.push_back(i);
  if (ls && lt && s[0] == t[0])
    S.size() < T.size() ? S.push_back(0) : T.push_back(0);
  sort(S.begin(), S.end());
  sort(T.begin(), T.end());
  for (int i = 0, j = 0, d = 0; i < S.size() || j < T.size();) {
    int x = (i == S.size() ? ls : S[i]);
    int y = (j == T.size() ? lt : T[i]);
    printf("%d %d\n", x + d, y - d);
    d += (y - d) - (x + d);
    i += (i != S.size());
    j += (j != T.size());
  }
}
