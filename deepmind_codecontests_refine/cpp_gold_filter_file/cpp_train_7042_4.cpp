#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  if (a % m == (b + 1) % m && m != 1 && b % m)
    puts("2");
  else
    printf("%d", ((a - 1) / m == (b - 1) / m
                      ? 1
                      : ((a - 1) / m == (b - 1) / m - 1
                             ? (!((a - 1) % m) && (!(b % m) || b == n) ? 1 : 2)
                             : 3 - !((a - 1) % m) - (!(b % m) || b == n))));
}
