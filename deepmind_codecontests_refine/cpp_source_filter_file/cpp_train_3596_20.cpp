#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e8 + 7;
long long n, k;
int main() {
  scanf("%lld%lld", &n, &k);
  int ans = 0;
  char c;
  int d;
  while (n--) {
    cin >> c >> d;
    if (c == '+')
      k += d;
    else if (c == '-') {
      if (k - d < 0)
        ans++;
      else
        k -= d;
    }
  }
  printf("%lld %lld\n", k, ans);
  return 0;
}
