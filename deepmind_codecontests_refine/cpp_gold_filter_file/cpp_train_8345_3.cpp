#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
char s[1100000];
string t;
double calc(string s) {
  int n = s.size(), p = 0, q = 0, cnt = 0, cur = 0, i;
  char ch;
  for (i = 0; i < n; i++) {
    ch = (q & 1) ? 'R' : 'L';
    if (s[i] == 'X')
      q++;
    else if (s[i] == ch)
      p++, q++, cur = 0;
    else
      p++, q += 2, cnt += cur, cur = !cur;
  }
  if (q & 1) q++, cnt += cur;
  if (p * 2 > q) p -= cnt, q -= 2 * cnt;
  return 1.0 * p / q;
}
int main() {
  int L, i;
  double ans;
  scanf("%s", s);
  L = 0;
  for (i = 0; s[i]; i++) {
    if (i && s[i] == s[i - 1] && s[i] != 'X') t += 'X';
    t += s[i];
  }
  if (t[0] == t[t.length() - 1] && t[0] != 'X')
    ans = max(calc(t + 'X'), calc('X' + t));
  else
    ans = calc(t);
  printf("%.6lf\n", floor(ans * 1e8) / 1e6);
  return 0;
}
