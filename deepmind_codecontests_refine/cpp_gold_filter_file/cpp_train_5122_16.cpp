#include <bits/stdc++.h>
using namespace std;
int n, p;
int main() {
  scanf("%d %d", &n, &p);
  for (int i = 1; i < 32; ++i) {
    int k = n - i * p;
    if (k > 0 && __builtin_popcount(k) <= i && i <= k) {
      printf("%d", i);
      return 0;
    }
  }
  puts("-1");
}
