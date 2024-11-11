#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  long long ts, tf, t;
  int n;
  scanf("%lld %lld %lld %d", &ts, &tf, &t, &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  a[n++] = tf - t + 1;
  sort(a, a + n);
  long long ans = 12345678901234LL;
  long long anst = 0;
  long long startt = ts;
  for (int i = 0; i < n;) {
    long long curt = a[i] - 1;
    long long actt = max(startt, curt);
    if (actt + t > tf) {
      break;
    }
    if (actt - curt < ans) {
      ans = actt - curt;
      anst = curt;
    }
    while (i < n && a[i] == curt + 1) {
      startt = max(startt, a[i]) + t;
      i++;
    }
  }
  printf("%lld\n", anst);
  return 0;
}
