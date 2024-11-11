#include <bits/stdc++.h>
using namespace std;
int n, tmp;
char s[500005];
double tot, ans, t1, t2, t3, t4;
int check(char i) {
  if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ||
      s[i] == 'Y')
    return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  scanf("%s", s);
  n = strlen(s);
  tmp = n / 2;
  if (n % 2) tmp++;
  tot = 0.0, t1 = 1.0;
  for (int i = 1; i <= tmp; i++) {
    tot += (1.0 / t1);
    t1 += 1.0;
  }
  t1 = 1.0;
  for (int i = 0; i < tmp; i++) {
    t2 = i + t1 * tot;
    if (i == tmp - 1 && n % 2)
      ans += t2 * (check(i) * 1.0);
    else {
      ans += t2 * (check(i) * 1.0);
      ans += t2 * (check(n - i - 1));
    }
    tot -= (1.0 / t1);
    t1 += 1.0;
  }
  tot = 0, t1 = tmp + 1.0;
  for (int i = tmp + 1; i <= n; i++) {
    tot += (1.0 / t1);
    t1 += 1.0;
  }
  if (n % 2) tmp--;
  t1 = n, t3 = 1.0, t4 = 0.0;
  for (int i = 0; i < tmp; i++) {
    t2 = tot * t3 + t4;
    ans += t2 * (check(i) * 1.0);
    ans += t2 * (check(n - i - 1) * 1.0);
    t4 += t3 / t1;
    tot -= (1.0 / t1);
    t1 -= 1.0;
    t3 += 1.0;
  }
  if (n % 2 && tmp) ans += t2 * (check(tmp) * 1.0);
  printf("%.10lf\n", ans);
  return 0;
}
