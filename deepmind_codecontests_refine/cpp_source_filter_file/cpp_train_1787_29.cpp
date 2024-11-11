#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sign = 1, sum = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') sign = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    sum = (sum << 1) + (sum << 3) + c - '0';
    c = getchar();
  }
  return sign * sum;
}
const int N = 3e6 + 50, inf = 2137483647;
long long ans = 0;
char st[N];
int main() {
  scanf("%s", st);
  for (int res = inf, i = strlen(st) - 1; i >= 0; --i) {
    for (int j = 1; i + (j << 1) < strlen(st); ++j)
      if (st[i + j] == st[i + (j << 1)] && st[i] == st[i + j]) {
        res = min(res, i + (j << 1));
        break;
      }
    if (res != inf) ans += strlen(st) - res;
  }
  printf("%d\n", ans);
}
