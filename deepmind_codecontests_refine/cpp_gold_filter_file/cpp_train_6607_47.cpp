#include <bits/stdc++.h>
using namespace std;
const int N = 3e5, inf = 1e9, mod = 1e9 + 7;
const long long linf = 1e18;
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2) {
    printf("1 ");
    for (int i = 2; i <= n; i += 2) printf("%d %d ", i + 1, i);
  } else {
    for (int i = 1; i <= n; i += 2) printf("%d %d ", i + 1, i);
  }
  return 0;
}
