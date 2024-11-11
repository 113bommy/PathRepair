#include <bits/stdc++.h>
using namespace std;
long a[2000002], b[2000002];
long i, n, maxn;
char ch;
int main() {
  scanf("%d", &n);
  a[0] = 1000000;
  maxn = 0;
  getchar();
  for (i = 1; i <= 2000001; i = i + 1) b[i] = -100;
  b[1000000] = 0;
  for (i = 1; i <= n; i = i + 1) {
    scanf("%c", &ch);
    if (ch == '0')
      a[i] = a[i - 1] + 1;
    else
      a[i] = a[i - 1] - 1;
    if (b[a[i]] == -100)
      b[a[i]] = i;
    else if (i - b[a[i]] > maxn)
      maxn = i - b[a[i]];
  }
  printf("%d\n", maxn);
  return 0;
}
