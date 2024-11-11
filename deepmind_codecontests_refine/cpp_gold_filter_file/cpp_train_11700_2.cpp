#include <bits/stdc++.h>
using namespace std;
char sa[2000010], sb[2000010];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s%s", sa, sb);
  int t1 = 0, t2 = 0, t3 = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (sa[i] == '1' && sb[i] == '0') t1++;
    if (sa[i] == '0' && sb[i] == '1') t2++;
    if (sa[i] == '1' && sb[i] == '1') t3++;
  }
  t3 %= 2;
  if (t1 > t2) {
    t1 -= t2;
    t2 = 0;
  } else {
    t2 -= t1;
    t1 = 0;
  }
  if (t3 == 0) {
    if (t1 != 0)
      puts("First");
    else if (t2 <= 1)
      puts("Draw");
    else
      puts("Second");
  } else {
    if (t2 == 0)
      puts("First");
    else if (t2 <= 2)
      puts("Draw");
    else
      puts("Second");
  }
  return 0;
}
