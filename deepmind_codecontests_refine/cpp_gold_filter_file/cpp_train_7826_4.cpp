#include <bits/stdc++.h>
using namespace std;
int t;
long long x, y;
int main() {
  cin >> t;
  while (t > 0) {
    t--;
    scanf("%lld%lld", &x, &y);
    x -= y;
    if (x == 1)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
