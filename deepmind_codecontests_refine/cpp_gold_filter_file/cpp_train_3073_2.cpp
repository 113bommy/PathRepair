#include <bits/stdc++.h>
using namespace std;
const int mx = 100000 + 100;
int len, op, n, a[mx], num[30];
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
char s[mx];
void solve1() {
  len = 0;
  for (int i = 1; i <= n; ++i) len += num[i];
  if (len & 1)
    printf("%d\n", op);
  else
    printf("%d\n", op * 2);
  for (int i = 1; i <= op; ++i) {
    int l = 0, r = len + 1;
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= num[j]; ++k) {
        if (num[j] % 2 == 1 && k == num[j])
          s[len / 2 + 1] = j - 1 + 'a';
        else if (k % 2 == 1)
          s[++l] = j - 1 + 'a';
        else
          s[--r] = j - 1 + 'a';
      }
    for (int j = 1; j <= len; ++j) putchar(s[j]);
  }
}
void solve2() {
  op /= 2;
  for (int i = 1; i <= n; ++i) num[i] *= 2;
  solve1();
}
void solve3() {
  cout << 0 << endl;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= a[i]; ++j) printf("%c", 'a' + i - 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  op = a[1];
  for (int i = 2; i <= n; ++i) op = gcd(op, a[i]);
  int ans = 0;
  for (int i = 1; i <= n; ++i) num[i] = a[i] / op;
  for (int i = 1; i <= n; ++i)
    if (num[i] % 2 == 1) ans++;
  if (!ans || ans == 1)
    solve1();
  else if (ans >= 2 && op % 2 == 0)
    solve2();
  else
    solve3();
  return 0;
}
