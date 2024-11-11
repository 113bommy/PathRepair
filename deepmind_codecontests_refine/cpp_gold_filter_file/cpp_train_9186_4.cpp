#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= 1005;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1005;
    a = a * a % 1005;
  }
  return res;
}
int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  int n = nxt();
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1)
    printf("%lld\n", a[0]);
  else if (n == 2)
    printf("%lld\n", a[0] | a[1]);
  else {
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          ans = max(ans, a[i] | a[j] | a[k]);
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
