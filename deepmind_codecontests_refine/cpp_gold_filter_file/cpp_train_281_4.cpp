#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
const long long M = 8007;
const long long mod = 5e9 + 7;
long long n, k;
long long a[N];
int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] + k < a[i]) {
      int j = i - 1;
      while (a[j] == a[i - 1]) {
        ans += 1;
        j -= 1;
      }
    }
  }
  int j = n;
  while (a[j] == a[n]) {
    j -= 1;
    ans += 1;
  }
  printf("%d\n", ans);
}
