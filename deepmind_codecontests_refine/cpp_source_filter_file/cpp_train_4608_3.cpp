#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n, m, a, b;
    scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
    if (min(n, m) < b || n + m < a + b)
      printf("No\n");
    else
      printf("Yes\n");
  }
}
