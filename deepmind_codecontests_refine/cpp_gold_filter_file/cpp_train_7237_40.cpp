#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  if (m & 1)
    printf("%d\n", 1 + (m - 1) / 2);
  else
    printf("%d\n", 1 + (n - m) / 2);
  return 0;
}
