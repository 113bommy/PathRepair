#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int tab[MAXN];
int main() {
  int n, a, z;
  scanf("%d %d", &n, &a);
  double x, y = 1e9;
  for (int i = 1; i <= n - 2; i++) {
    x = (180.0 * i) / n;
    if (abs(x - a) < y) y = abs(x - a), z = i;
  }
  printf("%d %d %d", 1, z + 2, z + 1);
}
