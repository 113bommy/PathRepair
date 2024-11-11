#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  printf("%lld", (n / k + 1) * k);
  return 0;
}
