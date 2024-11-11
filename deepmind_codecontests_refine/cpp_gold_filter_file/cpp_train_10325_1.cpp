#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int main() {
  scanf("%d", &n);
  long long sum = 0, mx = 0, tmp;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &tmp);
    sum += tmp;
    mx = max(mx, tmp);
  }
  if (!(sum & 1) && sum >= mx * 2)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
