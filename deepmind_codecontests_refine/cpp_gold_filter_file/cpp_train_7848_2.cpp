#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long int fact(int n) {
  long long int res = 1;
  for (int i = 0; i < n; ++i) res *= (i + 1);
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  random_shuffle(a.begin(), a.end());
  sort(a.begin(), a.end());
  long long int ans = 0;
  long long int sled = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i];
    ans += abs(a[i] - a[0]);
    sled += abs(a[i] - a[0]);
  }
  long long int pr = 0;
  for (int i = 1; i < n; i++) {
    pr += (a[i] - a[i - 1] + 0LL) * (i);
    sled -= (a[i] - a[i - 1] + 0LL) * (n - i);
    ans += pr + sled;
  }
  long long int g = gcd(ans, n);
  ans /= g;
  cout << ans << " " << n / g;
  puts("");
  return 0;
}
