#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  int n, m, sq, k, t;
  while (~scanf("%d%d%d", &n, &k, &t)) {
    if (t <= k)
      printf("%d\n", t);
    else if (t <= n)
      printf("%d\n", k);
    else
      printf("%d\n", t - n + 1);
  }
  return 0;
}
