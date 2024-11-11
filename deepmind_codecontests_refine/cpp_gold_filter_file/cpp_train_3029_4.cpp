#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
int calc(int n, int m, int x, int y) {
  if (n && m && x == y) n < m ? n++ : m++;
  return max(n, m) - 1;
}
char s[N], t[N];
vector<int> S, T;
int main() {
  scanf("%s%s", s, t);
  int ls = strlen(s), n = 0;
  int lt = strlen(t), m = 0;
  for (int i = (int)(0); i <= (int)(ls - 1); i++)
    n += (i == 0 || s[i] != s[i - 1]);
  for (int i = (int)(0); i <= (int)(lt - 1); i++)
    m += (i == 0 || t[i] != t[i - 1]);
  int ans = calc(n, m, s[0] == 'a', t[0] == 'a');
  int xx = 0, yy = 0, n2 = 0, m2 = 0;
  for (int i = (int)(0); i <= (int)(ls); i++)
    if (i == 0 || i == ls || s[i] != s[i - 1]) {
      m2 = 0;
      for (int j = (int)(0); j <= (int)(lt); j++)
        if (j == 0 || j == lt || t[j] != t[j - 1]) {
          int n3 = n - n2 + m2 - (i < ls && j && t[j - 1] == s[i]);
          int m3 = m - m2 + n2 - (j < lt && i && s[i - 1] == t[j]);
          int x3 = (j ? t[0] == 'a' : (i < ls ? s[i] == 'a' : 0));
          int y3 = (i ? s[0] == 'a' : (j < lt ? t[j] == 'a' : 0));
          int tmp = 1 + calc(n3, m3, x3, y3);
          if (tmp < ans) ans = tmp, xx = i, yy = j;
          m2++;
        }
      if ((++n2) > 3) break;
    }
  n2 = m2 = 0;
  for (int j = (int)(0); j <= (int)(lt); j++)
    if (j == 0 || j == lt || t[j] != t[j - 1]) {
      n2 = 0;
      for (int i = (int)(0); i <= (int)(ls); i++)
        if (i == 0 || i == ls || s[i] != s[i - 1]) {
          int n3 = n - n2 + m2 - (i < ls && j && t[j - 1] == s[i]);
          int m3 = m - m2 + n2 - (j < lt && i && s[i - 1] == t[j]);
          int x3 = (j ? t[0] == 'a' : (i < ls ? s[i] == 'a' : 0));
          int y3 = (i ? s[0] == 'a' : (j < lt ? t[j] == 'a' : 0));
          int tmp = 1 + calc(n3, m3, x3, y3);
          if (tmp < ans) ans = tmp, xx = i, yy = j;
          n2++;
        }
      if ((++m2) > 3) break;
    }
  int d = 0;
  printf("%d\n", ans);
  if (xx || yy) {
    static char ss[N], tt[N];
    for (int i = (int)(0); i <= (int)(ls - 1); i++) ss[i] = s[i];
    for (int i = (int)(0); i <= (int)(lt - 1); i++) tt[i] = t[i];
    int lS = ls, lT = lt;
    ls = lt = 0;
    for (int i = (int)(0); i <= (int)(yy - 1); i++) s[ls++] = tt[i];
    for (int i = (int)(xx); i <= (int)(lS - 1); i++) s[ls++] = ss[i];
    for (int i = (int)(0); i <= (int)(xx - 1); i++) t[lt++] = ss[i];
    for (int i = (int)(yy); i <= (int)(lT - 1); i++) t[lt++] = tt[i];
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
  int i = 0, j = 0;
  for (; i < S.size() || j < T.size();) {
    int x = (i == S.size() ? ls : S[i]);
    int y = (j == T.size() ? lt : T[j]);
    printf("%d %d\n", x + d, y - d);
    d += (y - d) - (x + d);
    if (i < S.size()) i++;
    if (j < T.size()) j++;
  }
}
