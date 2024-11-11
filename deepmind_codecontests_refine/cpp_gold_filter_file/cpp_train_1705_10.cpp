#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    int t = min(n, m);
    printf("%d\n", t + 1);
    for (int i = 0; i <= t; i++) printf("%d %d\n", t - i, i);
  }
  return 0;
}
