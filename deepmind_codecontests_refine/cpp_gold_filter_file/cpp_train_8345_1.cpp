#include <bits/stdc++.h>
using namespace std;
long double ans;
void work(string s) {
  int p = 0, q = 0, cnt = 0, cur = 0;
  for (int i = 0; i <= (int)s.size() - 1; i++) {
    char c = q & 1 ? 'R' : 'L';
    if (s[i] == 'X')
      q++;
    else if (s[i] == c)
      p++, q++, cur = 0;
    else
      p++, q += 2, cnt += cur, cur ^= 1;
  }
  if (q & 1) q++, cnt += cur;
  if (p * 2 > q) p -= cnt, q -= cnt * 2;
  ans = max(ans, (long double)1. * p / q);
}
string s, a;
int main() {
  cin >> s;
  for (int i = 0; i <= (int)s.size() - 1; i++) {
    if (i != 0 && s[i] == s[i - 1] && s[i] != 'X') a += 'X';
    a += s[i];
  }
  if (a[0] == a[a.size() - 1] && a[0] != 'X')
    work(a + 'X'), work('X' + a);
  else
    work(a);
  ans *= 100;
  printf("%.6lf\n", (double)max((long double)0., (ans - (5e-7))));
}
