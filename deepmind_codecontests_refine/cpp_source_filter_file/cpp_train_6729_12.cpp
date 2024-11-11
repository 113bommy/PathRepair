#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int a[MAXN];
void solve1(int n) {
  if (n & 1) {
    printf("NO\n");
    return;
  }
  puts("YES");
  int x = n;
  while (x) {
    int k = 0;
    while ((1 << k + 1) <= x) ++k;
    int i;
    for (i = 0; i + (1 << k) <= x; ++i) {
      a[i + (1 << k)] = (1 << k) - i - 1;
      a[(1 << k) - i - 1] = i + (1 << k);
    }
    x -= i + 1;
  }
  for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
}
void solve2(int n) {
  if (n < 7) {
    if (n == 6) {
      puts("YES");
      puts("3 6 2 5 1 4");
      return;
    }
    puts("NO");
    return;
  }
  int k = log(n) / log(2);
  if ((1 << k) == n || (1 << k + 1) == n) {
    puts("NO");
    return;
  }
  puts("YES");
  a[1] = 7, a[2] = 3, a[3] = 2, a[4] = 6, a[5] = 1, a[6] = 4, a[7] = 5;
  for (int k = 3; (1 << k) <= n; ++k) {
    int j;
    for (j = 0; j < (1 << k) - 1 && (1 << k) + j < n; ++j)
      a[(1 << k) + j] = (1 << k) + j + 1;
    a[(1 << k) + j] = (1 << k);
  }
  for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
}
int main() {
  int n;
  scanf("%d", &n);
  solve1(n);
  solve2(n);
}
