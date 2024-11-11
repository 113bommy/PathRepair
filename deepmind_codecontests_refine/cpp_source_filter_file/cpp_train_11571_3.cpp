#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  while (~scanf("%d %d", &n, &v)) {
    int cost;
    --n;
    if (v >= n)
      printf("%d\n", n);
    else {
      cost = n;
      for (int i = 2; i <= n - v + 1; i++) cost++;
      printf("%d\n", cost);
    }
  }
  return 0;
}
