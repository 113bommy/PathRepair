#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005], l[200005], r[200005], pos[200005];
inline int in() {
  int res, ff;
  res = ff = 0;
  char ch;
  if ((ch = getchar()) == '-')
    ff = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
  return ff ? -res : res;
}
int n;
int fastpow(int x, int y) {
  int ans, res;
  ans = 1;
  res = x;
  while (y) {
    if (y & 1) ans *= res;
    res *= res;
    y >>= 1;
  }
  return ans;
}
int main() {
  n = in();
  for (int i = 1; i <= n; i++) a[i] = in();
  sort(a + 1, a + 1 + n);
  int num = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1])
      num++;
    else
      break;
  }
  if (num <= num / 2)
    printf("Alice\n");
  else
    printf("Bob\n");
}
