#include <bits/stdc++.h>
using namespace std;
const int MOD = 1E9 + 7;
int main() {
  int n, c = 0;
  scanf("%d", &n);
  for (int i = 3; i <= n; ++i)
    for (int j = 5; j <= n; ++j) {
      int a = (i ^ j);
      if (a > j && (i + j) > a && a <= n && i < j) ++c;
    }
  return printf("%d\n", c), 0;
}
