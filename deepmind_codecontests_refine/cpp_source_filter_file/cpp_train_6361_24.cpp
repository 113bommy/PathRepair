#include <bits/stdc++.h>
using namespace std;
long long n, m;
char s[10];
int main() {
  srand(time(0));
  scanf("%I64d%I64d", &n, &m);
  long long l = 1, r = n;
  while (l < r) {
    if (r - l + 1 <= 50) {
      long long pos = l + rand() % (r - l + 1);
      printf("%I64d %I64d\n", pos, pos);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'Y') return 0;
      l = max(1ll, l - m);
      r = min(r + m, n);
      continue;
    }
    long long mid = (l + r) >> 1;
    printf("%I64d %I64d\n", l, mid);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'Y') {
      l = max(1ll, l - m);
      r = min(mid + m, n);
    } else {
      l = max(1ll, mid - m);
      r = min(r + m, n);
    }
  }
  printf("%I64d\n", l);
  fflush(stdout);
  return 0;
}
