#include <bits/stdc++.h>
using namespace std;
const int maxn = 105 + 7;
int n;
long long a, b, s[maxn];
long long sum = 0;
int main() {
  scanf("%d%lld%lld", &n, &a, &b);
  for (int i = 0; i < n; i++) scanf("%lld", &s[i]), sum += s[i];
  long long k = s[0] * a;
  int num = 0;
  sort(s + 1, s + n);
  if (k >= b * sum)
    printf("%d\n", num);
  else {
    for (int i = n - 1; i > 0; i--) {
      sum -= s[i];
      num++;
      if (k >= b * sum) {
        printf("%d\n", num);
        break;
      }
    }
  }
  return 0;
}
