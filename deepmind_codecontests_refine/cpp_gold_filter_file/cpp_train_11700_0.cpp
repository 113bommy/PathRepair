#include <bits/stdc++.h>
const int N = 2000010;
using namespace std;
char s[N], t[N];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s%s", s, t);
  int a[5] = {};
  for (int i = 0; i < 2 * n; i++) {
    a[((s[i] == '1') << 1) | (t[i] == '1')]++;
  }
  int s0 = 0, s1 = 0;
  int t = 0;
  while (a[3]) {
    if (t == 0)
      s0++;
    else
      s1++;
    a[3]--;
    t ^= 1;
  }
  while (a[2]) {
    if (t == 0)
      s0++, a[2]--;
    else
      a[2]--;
    t ^= 1;
  }
  while (a[1]) {
    if (t == 1)
      s1++, a[1]--;
    else
      a[1]--;
    t ^= 1;
  }
  if (s0 > s1)
    puts("First");
  else if (s0 == s1)
    puts("Draw");
  else
    puts("Second");
  return 0;
}
