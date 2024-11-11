#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 20;
char s[MAX], t[MAX];
int l[MAX], r[MAX];
int mm[26][MAX];
int main() {
  scanf("%s %s", s + 1, t + 1);
  s[0] = t[0] = '1';
  int slen = strlen(s) - 1, tlen = strlen(t) - 1;
  memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r));
  for (int i = (1); i <= (slen); ++i) {
    if (i == 1)
      l[i] = s[i] == t[i];
    else {
      l[i] = l[i - 1];
      if (l[i] != tlen && t[l[i - 1] + 1] == s[i]) l[i]++;
    }
  }
  for (int i = (slen); i >= (1); --i) {
    if (i == slen)
      r[i] = s[i] == t[tlen];
    else {
      r[i] = r[i + 1];
      if (r[i] != tlen && t[tlen - r[i - 1]] == s[i]) r[i]++;
    }
  }
  for (int c = (0); c <= (25); ++c) {
    for (int i = (1); i <= (tlen); ++i) mm[c][i] = 0;
  }
  for (int i = (1); i <= (tlen); ++i) {
    int val = t[i] - 'a';
    mm[val][i] = 1;
  }
  for (int c = (0); c <= (25); ++c) {
    for (int i = (2); i <= (tlen); ++i) {
      mm[c][i] = mm[c][i - 1] + mm[c][i];
    }
  }
  bool ok = 1;
  for (int i = (1); i <= (slen); ++i) {
    int val = s[i] - 'a';
    int zz = max(1, tlen - r[i + 1]);
    int yy = min(l[i - 1] + 1, tlen);
    if (zz > yy) ok = 0;
    int sum = zz == 1 ? mm[val][yy] : mm[val][yy] - mm[val][zz - 1];
    if (sum == 0) ok = 0;
    if (!ok) break;
  }
  if (ok)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
