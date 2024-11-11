#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
bool gao(int a, int b, int n, int x) {
  for (; abs(a) < INF * n; n--) a *= x;
  return a == b;
}
int main() {
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  for (int i = -2000; i <= 2000; i++)
    if (gao(a, b, n, i)) return !printf("%d\n", i);
  puts("No solution");
}
