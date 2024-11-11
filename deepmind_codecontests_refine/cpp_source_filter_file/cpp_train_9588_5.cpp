#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 1000000000000000000ll;
long long f[30000005];
bool check(long long x) {
  long long now = (long long)sqrt(x * 1.0);
  return now * now < x;
}
int main() {
  long long x;
  int len = 0;
  for (long long i = 2; i <= 1000000; i++) {
    x = i * i;
    while (x <= Maxn / i) {
      x *= i;
      if (check(x)) {
        f[++len] = x;
      }
    }
  }
  sort(f + 1, f + 1 + len);
  len = (int)(unique(f + 1, f + 1 + len) - f - 1);
  int t;
  scanf("%d", &t);
  long long n;
  while (t--) {
    cin >> n;
    x = lower_bound(f + 1, f + 1 + len, n) - f - 1;
    cout << n - x - (long long)sqrt(n * 1.0) << endl;
  }
  return 0;
}
