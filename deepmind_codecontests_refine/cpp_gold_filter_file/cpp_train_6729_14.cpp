#include <bits/stdc++.h>
const int N = 100005;
int n, a[N];
bool solve1(int n) {
  if (n & 1) return 0;
  int t = 1;
  while (t <= n) t <<= 1;
  for (int i = t - n - 1; i <= n; i++) a[i] = t - 1 - i;
  if (t - n - 2) return solve1(t - n - 2);
  return 1;
}
bool solve2(int n) {
  if (__builtin_popcount(n) == 1) return 0;
  if (n <= 5) return 0;
  puts("YES");
  if (n & 1) {
    printf("3 6 1 5 7 2 4 ");
    for (int i = 8; i <= n; i += 2) printf("%d %d ", i + 1, i);
  } else {
    printf("%d ", n - 1);
    for (int i = 2; i <= n - 3; i += 2) printf("%d %d ", i + 1, i);
    printf("%d %d %d\n", n, 1, n - 2);
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  if (solve1(n)) {
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
  } else
    puts("NO");
  if (!solve2(n)) puts("NO");
}
