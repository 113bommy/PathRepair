#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int id[maxn], u[maxn], v[maxn], x[maxn];
int main() {
  int n;
  scanf("%d", &n);
  if (n == 5) {
    puts("1 2 2");
    puts("1 3 1");
    puts("2 4 1");
    puts("4 5 1");
    puts("3 4");
    puts("3 5");
    return 0;
  }
  for (int i = 1; i <= n / 2; i++) printf("%d %d 1\n", i, i + n / 2);
  for (int i = n / 2 + 1, j = 1; i < n; i++, j += 2)
    printf("%d %d %d\n", i, i + 1, j);
  for (int i = 1; i < n / 2; i++) printf("%d %d\n", i, i + 1);
  puts("1 3");
}
