#include <bits/stdc++.h>
using namespace std;
int n, k;
string a, b;
int main() {
  scanf("%d %d", &n, &k);
  cin >> a >> b;
  long long ans = 0;
  long long x = 1;
  for (long long i = 0; i < n; i++) {
    x <<= 1;
    if (a[i] == 'b') x--;
    if (b[i] == 'a') x--;
    if (x > k) {
      ans += (n - i) * k;
      break;
    }
    ans += x;
  }
  printf("%lld\n", ans);
  return 0;
}
