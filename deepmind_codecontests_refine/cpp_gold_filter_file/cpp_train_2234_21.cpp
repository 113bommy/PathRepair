#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int k = (n + 1) / 2;
  k = k + ((m - k % m)) % m;
  if (k > n)
    puts("-1");
  else
    printf("%d\n", k);
  return 0;
}
