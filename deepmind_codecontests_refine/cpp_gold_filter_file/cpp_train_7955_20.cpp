#include <bits/stdc++.h>
using namespace std;
template <typename T>
void r1(T &x) {
  x = 0;
  char c(getchar());
  int f(1);
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
}
const int maxn = 2e5 + 5;
const int maxm = maxn << 1;
typedef int room[maxn];
int n, m;
signed main() {
  int i;
  r1(n);
  if (n == 5) {
    printf("1 2 3\n1 3 3\n2 4 2\n4 5 1\n3 4\n3 5\n");
  } else {
    int s = n / 2;
    for (i = 1; i <= s; ++i) printf("%d %d %d\n", i, i + s, 1);
    for (i = 1; i + s < n; ++i)
      printf("%d %d %d\n", i + s, i + s + 1, 2 * i - 1);
    for (i = 1; i < s; ++i) printf("%d %d\n", i, i + 1);
    printf("1 3\n");
  }
  return 0;
}
