#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  scanf("%lld%lld", &n, &m);
  long long int x, y;
  for (long long int i = 0; i < n; i++) scanf("%lld%lld", &x, &y);
  for (long long int i = 0; i < m; i++) scanf("%lld%lld", &x, &y);
  if (n >= m)
    puts("Yes");
  else
    puts("No");
}
