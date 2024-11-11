#include <bits/stdc++.h>
using namespace std;
char s[1000010], t[1000010];
int ss, ts, ar[26], br[26], c, q, p, mark[26];
int bs(int l, int r) {
  if (l == r) return l;
  if (r - l == 1) {
    int a = 0;
    for (int i = 0; i < 26; i++) a += br[i] * r - min(br[i] * r, ar[i]);
    if (a <= q) return r;
    return l;
  }
  int mid = (r + l) / 2;
  int b = 0;
  for (int i = 0; i < 26; i++) b += br[i] * mid - min(br[i] * mid, ar[i]);
  if (b <= q)
    return bs(mid, r);
  else
    return bs(l, mid - 1);
}
int main() {
  scanf("%s%s", s, t);
  ss = strlen(s);
  ts = strlen(t);
  for (int i = 0; i < ss; i++) {
    if (s[i] == '?')
      q++;
    else
      ar[s[i] - 'a']++;
  }
  for (int i = 0; i < ts; i++) br[t[i] - 'a']++;
  c = bs(0, ss / ts);
  p = 0;
  for (int i = 0; i < ss; i++) {
    if (s[i] == '?') {
      for (int j = 0; j < 26; j++)
        if (ar[j] < c * br[j]) {
          s[i] = 'a' + j;
          ar[j]++;
          break;
        }
    }
  }
  for (int i = 0; i < ss; i++)
    if (s[i] == '?') s[i] = 'z';
  printf("%s\n", s);
}
