#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", min(min(a, b), a + b + c / 3));
  }
  return 0;
}
