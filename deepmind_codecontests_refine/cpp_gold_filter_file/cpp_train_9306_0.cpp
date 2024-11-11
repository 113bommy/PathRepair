#include <bits/stdc++.h>
using namespace std;
int x[40000];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < (int)n; ++i) scanf("%d", &x[i]);
  int ans = 0;
  for (int i = 0; i < (int)n; ++i)
    for (int j = 0; j < (int)i; ++j)
      if (abs(x[i] - x[j]) <= d) ans++;
  printf("%d\n", 2 * ans);
  return 0;
}
