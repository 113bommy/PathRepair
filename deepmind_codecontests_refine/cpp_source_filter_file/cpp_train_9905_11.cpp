#include <bits/stdc++.h>
using namespace std;
template <typename tn>
void read(tn &a) {
  tn x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  a = x * f;
}
int a[5050], b[5005];
int n, c, l, r, lft, rgt, l1, r1, cnt1, cnt2, cnt3;
bool flag = false;
int main() {
  read(n);
  for (int i = 1; i <= n; i++) a[i] = getchar();
  a[0] = getchar();
  for (int i = 1; i <= n; i++) b[i] = getchar();
  for (int i = 1; i <= n; i++) {
    if (a[i] == '1' && b[i] == '1') cnt1++;
    if (a[i] == '1' && b[i] == '0') cnt2++;
    if (a[i] == '0' && b[i] == '1') cnt3++;
  }
  for (int i = 0; i <= cnt2; i++)
    for (int j = 0; j <= cnt3; j++) {
      int tmp = cnt1;
      l1 = 0, r1 = 0;
      int c = i - j;
      lft = i + cnt3 - j, rgt = j + cnt2 - i;
      if (c < 0)
        lft -= c, tmp += c, l1 -= c;
      else
        rgt += c, tmp -= c, r1 += c;
      if (tmp % 2 || tmp < 0) continue;
      tmp /= 2;
      lft += tmp, rgt += tmp, l1 += tmp, r1 += tmp;
      if (lft > n / 2 || rgt > n / 2) continue;
      if (lft < 0 || rgt < 0) continue;
      l = i, r = j, flag = true;
      break;
    }
  if (!flag) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == '1' && b[i] == '1')
      if (l1) l1--, cout << i << ' ';
    if (a[i] == '1' && b[i] == '0')
      if (l) l--, cout << i << ' ';
    if (a[i] == '0' && b[i] == '1')
      if (cnt3 - r) cnt3--, cout << i << ' ';
    if (a[i] == '0' && b[i] == '0')
      if (n / 2 - lft) lft++, cout << i << ' ';
  }
  return 0;
}
