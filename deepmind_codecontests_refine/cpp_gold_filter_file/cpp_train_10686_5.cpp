#include <bits/stdc++.h>
using namespace std;
long long n;
long long dfs(long long i) {
  if (i % 2) return 0 * printf("%I64d\n", (i + 1) / 2);
  dfs(n - i / 2 + i);
}
int main() {
  long long q, x;
  scanf("%I64d %I64d", &n, &q);
  while (q--) {
    scanf("%I64d", &x);
    dfs(x);
  }
}
