#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int d = (n - k) / 2 + 1;
  for (int i = 1; i <= n; i++) printf("%d ", (i % d == 0));
  return 0;
}
